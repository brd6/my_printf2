/*
** utils.c for utils in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:28:58 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 20:54:36 2016 Berdrigue Bongolo-Beto
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

void		check_width_and_precision(int *wd,
					  int *lp,
					  int nbr,
					  t_ptf_format *ptf_f)
{
  if (*lp > printf_nbr_len(nbr))
    *lp = *lp - printf_nbr_len(nbr);
  else
    *lp = 0;
  if (*wd > (printf_nbr_len(nbr) + *lp))
    *wd = *wd - (printf_nbr_len(nbr) + *lp);
  else
    *wd = 0;
}

void		check_width_and_precision2(int *wd,
					   int *lp,
					   char *s,
					   t_ptf_format *ptf)
{
  if (*lp > printf_my_strlen(s))
    *lp = *lp - printf_my_strlen(s);
  else
    *lp = 0;
  if (*wd > (printf_my_strlen(s) + *lp))
    *wd = *wd - (printf_my_strlen(s) + *lp);
  else
    *wd = 0;
}
