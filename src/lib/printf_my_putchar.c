/*
** printf_my_putchar.c for printf_my_putchar in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 17:28:38 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 17:29:12 2016 Berdrigue Bongolo-Beto
*/

#include <unistd.h>

int		printf_my_putchar(int fd, char c)
{
  write(fd, &c, 1);
  return (1);
}
