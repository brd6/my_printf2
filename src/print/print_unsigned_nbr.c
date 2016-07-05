/*
** print_unsigned_nbr.c for print_unsigned_nbr in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jul  5 20:35:46 2016 Berdrigue Bongolo-Beto
** Last update Tue Jul  5 20:58:44 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static void	reset_len_p(t_ptf_format *format, t_print_elem *elem)
{
  if (getchar_pos(format->flags, '0') != -1 &&
      getchar_pos(format->flags, '-') != -1)
    {
      elem->len_precision = elem->width;
      elem->width = 0;
    }
}

int		print_unsigned_nbr(char *str, va_list ap, t_ptf_format *format)
{
  t_print_elem	elem;
  unsigned int	nbr;
  int		cp;
  int		res_set_prec;
  char		*s;
  int		dies_pos;

  if ((dies_pos = getchar_pos(format->flags, '#')) != -1)
    format->flags[dies_pos] = '_';
  elem.buff[1] = 0;
  nbr = va_arg(ap, unsigned int);
  set_width(&elem.width, format, ap);
  res_set_prec = set_prec_len(&elem.len_precision, format, ap);
  s = printf_my_itoa(nbr);
  cp = printf_my_strlen(s);
  if (!res_set_prec || elem.len_precision < cp)
    elem.len_precision = 0;
  elem.width = (elem.width > cp) ? elem.width : 0;
  cp = printf_my_strlen(s);
  check_width_and_precision2(&elem, s, format);
  reset_len_p(format, &elem);
  if (getchar_pos(format->flags, '-') != -1)
    cp = cp + prt_cond(&elem, s, str, format);
  else
    cp = cp + prt_cond2(&elem, s, str, format);
  return (cp);
}
