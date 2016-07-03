/*
** global_handler.c for global_handler in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 11:23:42 2016 Berdrigue Bongolo-Beto
** Last update Sun Jul  3 14:24:36 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static int	get_tab_index(t_printf *tab, char c)
{
  int		i;

  i = 0;
  while (tab && tab[i].func != NULL)
    {
      if (tab[i].type == c)
	return (i);
      i++;
    }
  return (-1);
}

static void	simple_print(char *str, const char *format, int *i)
{
  char		buff[2];

  if (format[*i] == '%' &&
      format[*i + 1] == ' ' &&
      !check_next_char(&format[*i + 1]))
    {
      check_print_limit_size(str, "% ");
      *i = *i + 1;
      skip_char(format, i, ' ');
      *i = *i - 1;
    }
  else
    {
      buff[0] = format[*i];
      buff[1] = 0;
      check_print_limit_size(str, buff);
    }
}

static void	free_ptf_format(t_ptf_format *format)
{
  free(format->field_width);
  free(format->precision);
}

int		global_handler(char *str,
			       const char *format,
			       va_list ap,
			       t_printf *tab)
{
  int		i;
  t_ptf_format	ptf_format;
  int		index;

  i = 0;
  while (format && format[i])
    {
      if (format[i] == '%' && format[i + 1] && check_next_char(&format[i + 1]))
	{
	  if (!init_ptf_format(format, &i, &ptf_format))
	    return ((g_prog.i = -1));
	  if ((index = get_tab_index(tab, ptf_format.conv_char)) != -1)
	    tab[index].func(str, ap, &ptf_format);
	  free_ptf_format(&ptf_format);
	}
      else
	simple_print(str, format, &i);
      i++;
    }
  if (g_prog.is_sprintf)
    str[(g_prog.is_sprintf == IS_SPRINTF) ? g_prog.i : g_prog.size_limit] = 0;
  return (g_prog.i);
}
