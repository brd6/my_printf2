/*
** print_nbr.c for print_nbr in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 11:40:25 2016 Berdrigue Bongolo-Beto
** Last update Sat Jul  2 19:59:48 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

static void	set_nb_sign(int *nbr,
			    int *nbr_bak,
			    int res_set_prec,
			    int *len_precision)
{
  if (*nbr < 0)
    {
      *nbr_bak = *nbr;
      *nbr = *nbr * (-1);
    }
  if (!res_set_prec || (*len_precision < printf_nbr_len(*nbr)))
    *len_precision = 0;
}

static int	nbr_precision_handler(int width,
				      int len_precision,
				      int nbr_bak,
				      t_ptf_format *format)
{
  int		cp;

  cp = 0;
  if (getchar_pos(format->flags, '+') != -1 && nbr < 0
}

int		print_nbr(char *str, va_list ap, t_ptf_format *format)
{
  int		width;
  int		res_set_prec;
  int		len_precision;
  int		nbr;
  int		nbr_bak;
  int		cp;

  set_width(&width, format, ap);
  res_set_prec = set_prec_len(&len_precision, format, ap);
  nbr = va_arg(ap, int);
  nbr_bak = nbr;
  set_nb_sign(&nbr, &nbr_bak);
  cp = printf_nbr_len(nbr);
  width = (width > cp) ? width : 0;
  check_width_and_precision(&width, &len_precision, nbr, format);
  if (getchar_pos(format->flags, '-') != -1)
    cp += nbr_precision_handler(width, len_precision, nbr_bak, format);
  else
    cp += pnbr_sd(format, &nbr_bak, width, len_precision);
  return (0);
}
