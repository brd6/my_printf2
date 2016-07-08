/*
** print_percent.c for print_percent in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jul  2 00:13:30 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:53:57 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_percent(char *str, va_list ap, t_ptf_format *format)
{
  char		buff[2];

  (void)(ap);
  (void)(format);
  buff[1] = 0;
  buff[0] = '%';
  return (check_print_limit_size(str, buff));
}
