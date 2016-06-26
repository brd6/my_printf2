/*
** global_handler.c for global_handler in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 11:23:42 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 21:42:04 2016 Berdrigue Bongolo-Beto
*/

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
  if (format[*i] == '%' &&
      format[*i + 1] == ' ' &&
      !check_next_char(&format[*i + 1]))
    {
      if ((g_prog.is_sprintf == IS_SNPRINTF &&
	   g_prog.i < g_prog.size_limit) ||
	  (g_prog.is_sprintf == IS_SPRINTF))
	printf_my_strcpy("% ", &str[g_prog.i]);
      else
	printf_my_putstr(g_prog.fd, "% ");
      g_prog.i += 2;
      *i = *i + 1;
      skip_char(format, i, ' ');
      *i = *i - 1;
    }
  else
    {
      if ((g_prog.is_sprintf == IS_SNPRINTF &&
	   g_prog.i < g_prog.size_limit) ||
	  (g_prog.is_sprintf == IS_SPRINTF))
	str[g_prog.i] = format[*i];
      else
	printf_my_putchar(g_prog.fd, format[*i]);
      g_prog.i++;
    }
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
      if (format[i] == '%' && check_format(&format[i]) &&
	  check_next_char(&format[i + 1]))
	{
	  if (!init_ptf_format(format, &i, &ptf_format))
	    return ((g_prog.i = -1));
	  if ((index = get_tab_index(tab, ptf_format.conv_char)) != -1)
	    tab[index].func(str, ap, &ptf_format);
	}
      else
	simple_print(str, format, &i);
      i++;
    }
  if (g_prog.is_sprintf)
    str[(g_prog.is_sprintf == IS_SPRINTF) ? g_prog.i : g_prog.size_limit] = 0;
  return (g_prog.i);
}
