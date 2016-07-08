/*
** print_ncount.c for print_ncount in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Jul  6 21:02:02 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:55:16 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_ncount(char *str, va_list ap, t_ptf_format *format)
{
  int		*nbr;

  (void)(str);
  (void)(format);
  nbr = va_arg(ap, int *);
  *nbr = g_prog.i;
  return (0);
}
