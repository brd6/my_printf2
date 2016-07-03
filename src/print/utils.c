/*
** utils.c for utils in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:28:58 2016 Berdrigue Bongolo-Beto
** Last update Sun Jul  3 11:20:49 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

void		set_width(int *width,
			  t_ptf_format *ptf_format,
			  va_list ap)
{
  if (ptf_format->field_width != 0 && ptf_format->field_width[0] == '*')
    *width = va_arg(ap, int);
  else if (ptf_format->field_width != 0 && ptf_format->field_width[0] != '*')
    *width = printf_my_atoi(ptf_format->field_width);
  else
    *width = -1;
}


int		set_prec_len(int *len, t_ptf_format *ptf_format, va_list ap)
{
  if (ptf_format->precision != 0 && ptf_format->precision[0] == '*')
    {
      *len = va_arg(ap, int);
      return (1);
    }
  else if (ptf_format->precision != 0 && ptf_format->precision[0] != '*')
    {
      *len = printf_my_atoi(ptf_format->precision);
      return (1);
    }
  return (0);
}

void		check_width(int *width, int cp)
{
  if (*width < cp && *width != -1)
    *width = cp;
  else if (*width == -1)
    *width = 0;
}

void		check_width_and_precision(t_print_elem *elem,
					  int nbr,
					  t_ptf_format *ptf_f)
{
  if (elem->len_precision > printf_nbr_len(nbr))
    elem->len_precision = elem->len_precision - printf_nbr_len(nbr);
  else
    elem->len_precision = 0;
  if (elem->width > (printf_nbr_len(nbr) + elem->len_precision))
    elem->width = elem->width - (printf_nbr_len(nbr) + elem->len_precision);
  else
    elem->width = 0;
}

void		check_width_and_precision2(t_print_elem *elem,
					   char *s,
					   t_ptf_format *ptf)
{
  if (elem->len_precision > printf_my_strlen(s))
    elem->len_precision = elem->len_precision - printf_my_strlen(s);
  else
    elem->len_precision = 0;
  if (elem->len_precision > (printf_my_strlen(s) + elem->len_precision))
    elem->width = elem->width - (printf_my_strlen(s) + elem->len_precision);
  else
    elem->width = 0;
}
