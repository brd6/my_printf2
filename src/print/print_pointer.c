/*
** print_pointer.c for print_pointer in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Tue Jul  5 21:29:59 2016 Berdrigue Bongolo-Beto
** Last update Tue Jul  5 21:51:35 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_pointer(char *str, va_list ap, t_ptf_format *format)
{
  unsigned int	nbr;
  int		cp;
  char		*s;

  nbr = va_arg(ap, unsigned int);
  if (nbr <= 0)
    cp = check_print_limit_size(str, POINTER_NULL_FLG);
  else
    {
      cp = check_print_limit_size(str, HEXA_SYMBOL_L);
      s = printf_convert_base(s2, BASE_DECIMAL, BASE_HEXA_);
      cp += check_print_limit_size(str, s);
    }
  return (cp);
}
