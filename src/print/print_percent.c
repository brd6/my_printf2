/*
** print_percent.c for print_percent in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jul  2 00:13:30 2016 Berdrigue Bongolo-Beto
** Last update Sat Jul  2 00:16:37 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_percent(char *str, va_list ap, t_ptf_format *format)
{
  g_prog.i++;
  return (printf_my_putchar(g_prog.fd, '%'));
}
