/*
** init_format.c for init_format in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 11:47:30 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 18:54:35 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

static void	init_flag(char flag,
			  int *flag_cp,
			  t_ptf_format *ptf_format,
			  int *v_set)
{
  if (*v_set == 0)
    {
      ptf_format->flags[0] = 0;
      ptf_format->field_width = 0;
      ptf_format->precision = 0;
      ptf_format->length_modifier = 0;
      *flag_cp = 0;
      *v_set = 1;
    }
  if (getchar_pos("-+ 0#", flag) != -1 && *flag_cp < 3)
    {
      ptf_format->flags[*flag_cp] = flag;
      if (*flag_cp == 1)
	ptf_format->flags[2] = 0;
      else
	ptf_format->flags[1] = 0;
      *flag_cp = *flag_cp + 1;
    }
}

static int	cmp_num(char c)
{
  return (is_num(c, 0));
}

static int	init_field_width(const char *format,
				 int *i,
				 int *var_set,
				 t_ptf_format *pt_f)
{
  if (!(*var_set == 1 && format[*i - 1] != '.'))
    return (1);
  if (format[*i] == '*')
    {
      if ((pt_f->field_width = printf_my_strdup("*")) == NULL)
	return (0);
      *var_set = 2;
    }
  else if (is_num(format[*i], 1) && pt_f->field_width == 0)
    {
      if ((pt_f->field_width = printf_my_getstr(&format[*i], cmp_num)) == NULL)
	return (0);
      *var_set = 2;
    }
  return (1);
}

static void	init_precision(const char *format,
			       int *i,
			       int *var_set,
			       t_ptf_format *pt_form)
{
  if (format[*i - 1] == '.' && format[*i] != '*')
    pt_form->precision = printf_my_getstr(&format[*i], cmp_num);
  else if (format[*i - 1] == '.' && format[*i] == '*')
    pt_form->precision = printf_my_strdup("*");
}

int		init_ptf_format(const char *format,
				int *i,
				t_ptf_format *ptf_format)
{
  int		flag_cp;
  int		var_set;

  *i = *i + 1;
  var_set = 0;
  while (format && format[*i])
    {
      init_flag(format[*i], &flag_cp, ptf_format, &var_set);
      skip_char(format, i, ' ');
      if (!init_field_width(format, i, &var_set, ptf_format))
	return (0);
      init_precision(format, i, &var_set, ptf_format);
      if (getchar_pos("hl", format[*i]) != -1)
	ptf_format->length_modifier = format[*i];
      else if (is_alpha(format[*i], 0) || format[*i] == '%')
	{
	  if (format[*i] == 'n' &&
	      (ptf_format->field_width = printf_my_itoa(g_prog.i)) == NULL)
	    return (0);
	  ptf_format->conv_char = format[*i];
	  return (1);
	}
      *i = *i + 1;
    }
  return (1);
}
