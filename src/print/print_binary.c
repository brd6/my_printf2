/*
** print_binary.c for print_binary in /home/bongol_b/ProjetPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Wed Jul  6 21:40:59 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:55:51 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

int		print_binary(char *str, va_list ap, t_ptf_format *format)
{
  int		nbr;
  char		*s;
  char		*s2;
  int		cp;

  (void)(format);
  nbr = va_arg(ap, int);
  s2 = printf_my_itoa(nbr);
  s = printf_convert_base(s2, BASE_DECIMAL, BASE_BINARY);
  cp = check_print_limit_size(str, s);
  free(s);
  free(s2);
  return (cp);
}
