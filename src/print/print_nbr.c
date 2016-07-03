/*
** print_nbr.c for print_nbr in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 11:40:25 2016 Berdrigue Bongolo-Beto
** Last update Sun Jul  3 14:37:28 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static void	set_nb_sign(int *nbr, int *nbr_bak)
{
  if (*nbr < 0)
    {
      *nbr_bak = *nbr;
      *nbr = *nbr * (-1);
    }
}

static void	set_mod_len_p(t_ptf_format *format, t_print_elem *elem, int nbr)
{
  if (getchar_pos(format->flags, '0') != -1 && format->precision == 0)
    {
      elem->len_precision = elem->width;
      elem->width = 0;
      if (nbr < 0)
	elem->len_precision = elem->len_precision - 1;
    }
}

static int	pnbr_sd(t_ptf_format *format,
			int *nbr,
			t_print_elem *elem,
			char *str)
{
  int		cp;

  set_mod_len_p(format, elem, *nbr);
  if ((cp = 0) == 0 && (getchar_pos(format->flags, '+') != -1 || *nbr < 0))
    {
      elem->width = elem->width - 1;
      g_prog.i += (++cp);
    }
  cp += print_nchar(' ', elem->width, str);
  if ((getchar_pos(format->flags, '+') != -1 && *nbr < 0) || *nbr < 0)
    {
      elem->buff[0] = '-';
      check_print_limit_size(str, elem->buff);
      *nbr = *nbr * (-1);
    }
  else if (getchar_pos(format->flags, '+') != -1 && *nbr > 0)
    {
      elem->buff[0] = '+';
      check_print_limit_size(str, elem->buff);
    }
  cp += nbr_space_handler(format, *nbr, elem, str) +
    print_nchar('0', elem->len_precision, str);
  elem->s = printf_my_itoa(*nbr);
  check_print_limit_size(str, elem->s);
  return (free(elem->s), cp);
}

static int	nbr_precision_handler(t_print_elem *elem,
				      int nbr, t_ptf_format *format,
				      char *str)
{

}

int		print_nbr(char *str, va_list ap, t_ptf_format *format)
{
  t_print_elem	elem;
  int		nbr;
  int		nbr_bak;
  int		cp;
  int		res_set_prec;

  set_width(&elem.width, format, ap);
  res_set_prec = set_prec_len(&elem.len_precision, format, ap);
  nbr = va_arg(ap, int);
  nbr_bak = nbr;
  set_nb_sign(&nbr, &nbr_bak);
  if (!res_set_prec || elem.len_precision < printf_nbr_len(nbr))
    elem.len_precision = 0;
  cp = printf_nbr_len(nbr);
  elem.width = (elem.width > printf_nbr_len(nbr) ? elem.width : 0);
  check_width_and_precision(&elem, nbr, format);
  elem.buff[1] = 0;
  if (getchar_pos(format->flags, '-') != -1)
    cp = cp + nbr_precision_handler(&elem, nbr_bak, format, str);
  else
    cp = cp + pnbr_sd(format, &nbr_bak, &elem, str);
  return (cp);
}
