/*
** printf_my_putstr.c for printf_my_putstr in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 17:25:44 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 19:41:41 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		printf_my_putstr(int fd, const char *s)
{
  int		i;

  i = 0;
  while (s && s[i])
    i += printf_my_putchar(fd, s[i]);
  return (i);
}
