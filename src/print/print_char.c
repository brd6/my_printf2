/*
** print_char.c for print_char in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:15:32 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 21:29:57 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

static void	print(char *str, char c)
{
  if ((g_prog.is_sprintf == IS_SNPRINTF &&
       g_prog.i < g_prog.size_limit) ||
      (g_prog.is_sprintf == IS_SPRINTF))
    str[g_prog.i] = c;
  else
    printf_my_putchar(g_prog.fd, c);
}

int		print_char(char *str, va_list ap, t_ptf_format *format)
{
  char		c;
  int		len_precision;
  int		width;
  int		cp;

  c = (char)(va_arg(ap, int));
  cp = 1;
  len_precision = 1;
  set_width(&width, format, ap);
  check_width(&width, g_prog.i);
  if (getchar_pos(format->flags, '-') != -1)
    {
      print(str, c);
      cp += print_nchar(' ', width - len_precision);
    }
  else
    {
      cp += print_nchar(' ', width - len_precision);
      print(str, c);
    }
  g_prog.i += cp;
  return (cp);
}
