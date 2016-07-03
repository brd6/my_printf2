/*
** print_char.c for print_char in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:15:32 2016 Berdrigue Bongolo-Beto
** Last update Sun Jul  3 11:53:45 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_char(char *str, va_list ap, t_ptf_format *format)
{
  t_print_elem	elem;
  int		cp;

  elem.buff[0] = (char)(va_arg(ap, int));
  elem.buff[1] = 0;
  elem.len_precision = 1;
  set_width(&elem.width, format, ap);
  check_width(&elem.width, 1);
  if (getchar_pos(format->flags, '-') != -1)
    {
      check_print_limit_size(str, elem.buff);
      cp = print_nchar(' ', elem.width - elem.len_precision, str);
    }
  else
    {
      cp = print_nchar(' ', elem.width - elem.len_precision, str);
      check_print_limit_size(str, elem.buff);
    }
  g_prog.i += cp;
  return (cp);
}
