/*
** print_octal.c for print_octal in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Jul  4 20:45:52 2016 Berdrigue Bongolo-Beto
** Last update Tue Jul  5 20:50:25 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

int		prt_cond(t_print_elem *elem,
			 char *s,
			 char *str,
			 t_ptf_format *format)
{
  int		cp;

  cp = 0;
  if (getchar_pos(format->flags, '#') != -1 && elem->len_precision == 0)
    {
      elem->buff[0] = '0';
      cp += check_print_limit_size(str, elem->buff);
      elem->width--;
    }
  else
    cp += print_nchar('0', elem->len_precision, str);
  check_print_limit_size(str, s);
  cp += print_nchar(' ', elem->width, str);
  return (free(s), cp);
}

int		prt_cond2(t_print_elem *elem,
			  char *s,
			  char *str,
			  t_ptf_format *format)
{
  int		cp;

  cp = 0;
  if (getchar_pos(format->flags, '#') != -1 && elem->len_precision == 0)
    elem->width--;
  cp += print_nchar(' ', elem->width, str);
  if (getchar_pos(format->flags, '#') != -1 && elem->len_precision == 0)
    {
      elem->buff[0] = '0';
      cp += check_print_limit_size(str, elem->buff);
    }
  else
    cp += print_nchar('0', elem->len_precision, str);
  check_print_limit_size(str, s);
  return (free(s), cp);
}

int		print_octal(char *str, va_list ap, t_ptf_format *format)
{
  t_print_elem	elem;
  unsigned int	nbr;
  int		cp;
  int		res_set_prec;
  char		*s;
  char		*s2;

  elem.buff[1] = 0;
  nbr = va_arg(ap, unsigned int);
  set_width(&elem.width, format, ap);
  res_set_prec = set_prec_len(&elem.len_precision, format, ap);
  s2 = printf_my_itoa(nbr);
  s = printf_convert_base(s2, BASE_DECIMAL, BASE_OCTAL);
  cp = printf_my_strlen(s);
  if (!res_set_prec || elem.len_precision < cp)
    elem.len_precision = 0;
  elem.width = (elem.width > cp) ? elem.width : 0;
  cp = printf_my_strlen(s);
  check_width_and_precision2(&elem, s, format);
  if (getchar_pos(format->flags, '-') != -1)
    cp = cp + prt_cond(&elem, s, str, format);
  else
    cp = cp + prt_cond2(&elem, s, str, format);
  return (free(s2), cp);
}
