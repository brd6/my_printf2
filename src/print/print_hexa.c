/*
** print_hexa.c for print_hexa in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jul  5 21:09:38 2016 Berdrigue Bongolo-Beto
** Last update Wed Jul  6 20:59:17 2016 Berdrigue Bongolo-Beto
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

static int	prt_cond_hexa2(t_print_elem *elem,
			       char *s,
			       t_ptf_format *format,
			       char *str)
{
  int		cp;

  if (getchar_pos(format->flags, '#') != -1 && elem->len_precision)
    elem->width -= 2;
  cp = print_nchar(' ', elem->width, str);
  if (getchar_pos(format->flags, '#') != -1)
    cp += check_print_limit_size(str, GET_HEXA_SYMBOL());
  else
    cp += print_nchar('0', elem->len_precision, str);
  cp += check_print_limit_size(str, s);
  return (free(s), cp);
}

static int	prt_cond_hexa(t_print_elem *elem,
			      char *s,
			      t_ptf_format *format,
			      char *str)
{
  int		cp;

  if (getchar_pos(format->flags, '#') != -1 && elem->len_precision == 0)
    {
      cp = check_print_limit_size(str, GET_HEXA_SYMBOL());
      elem->width--;
    }
  else
    cp = print_nchar('0', elem->len_precision, str);
  cp += check_print_limit_size(str, s);
  cp += print_nchar(' ', elem->width, str);
  return (free(s), cp);
}

int		print_hexa(char *str, va_list ap, t_ptf_format *format)
{
  t_print_elem	elem;
  unsigned int	nbr;
  int		cp;
  int		res_set_prec;
  char		*s;
  char		*s2;

  nbr = va_arg(ap, unsigned int);
  set_width(&elem.width, format, ap);
  res_set_prec = set_prec_len(&elem.len_precision, format, ap);
  s2 = printf_my_itoa(nbr);
  s = printf_convert_base(s2, BASE_DECIMAL, GET_HEXA_BASE());
  cp = printf_my_strlen(s);
  if (!res_set_prec || elem.len_precision < cp)
    elem.len_precision = 0;
  elem.width = (elem.width > cp) ? elem.width : 0;
  cp = printf_my_strlen(s);
  check_width_and_precision2(&elem, s, format);
  reset_len_p(format, &elem);
  if (getchar_pos(format->flags, '-') != -1)
    cp = cp + prt_cond_hexa(&elem, s, format, str);
  else
    cp = cp + prt_cond_hexa2(&elem, s, format, str);
  return (free(s2), cp);
}
