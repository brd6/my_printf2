/*
** print_str.c for print_str in /home/bongol_b/ProjetPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Jul  4 00:16:07 2016 Berdrigue Bongolo-Beto
** Last update Thu Jul  7 22:40:26 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static char	*init_var_arg_string(va_list ap, t_print_elem *elem)
{
  char		*s;

  s = printf_my_strndup((char *)va_arg(ap, char *), elem->len_precision);
  if (s == NULL)
    {
      s = printf_my_strdup(STR_NULL_FLG);
      elem->len_precision = printf_my_strlen(STR_NULL_FLG);
    }
  return (s);
}

int		print_str(char *str, va_list ap, t_ptf_format *format)
{
  t_print_elem	elem;
  int		cp;
  int		res_set_prec;
  char		*s;

  set_width(&elem.width, format, ap);
  res_set_prec = set_prec_len(&elem.len_precision, format, ap);
  s = init_var_arg_string(ap, &elem);
  cp = printf_my_strlen(s);
  if (!res_set_prec)
    res_set_prec = cp;
  cp = (elem.len_precision > cp) ? cp : elem.len_precision;
  check_width(&elem.width, cp);
  if (getchar_pos(format->flags, '-') != -1)
    {
      check_print_limit_size(str, s);
      cp += print_nchar(' ', elem.width - elem.len_precision, str);
    }
  else
    {
      cp += print_nchar(' ', elem.width - elem.len_precision, str);
      check_print_limit_size(str, s);
    }
  return (free(s), cp);
}
