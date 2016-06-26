/*
** utils2.c for utils2 in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:56:00 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 21:09:07 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_nchar(char c, int n)
{
  int		i;

  i = 0;
  while (i < n)
    {
      i += printf_my_putchar(g_prog.fd, c);
    }
  n = (n < 0) ? 0 : n;
  return (n);
}
