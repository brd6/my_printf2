/*
** print_char.c for print_char in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:15:32 2016 Berdrigue Bongolo-Beto
** Last update Sat Jul  2 12:46:33 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_char(char *str, va_list ap, t_ptf_format *format)
{
  char		buff[2];
  int		len_precision;
  int		width;
  int		cp;

  buff[0] = (char)(va_arg(ap, int));
  buff[1] = 0;
  len_precision = 1;
  set_width(&width, format, ap);
  check_width(&width, g_prog.i);
  if (getchar_pos(format->flags, '-') != -1)
    {
      check_print_limit_size(str, buff);
      cp = print_nchar(' ', width - len_precision);
    }
  else
    {
      cp = print_nchar(' ', width - len_precision);
      check_print_limit_size(str, buff);
    }
  g_prog.i += cp;
  return (cp + 1);
}
