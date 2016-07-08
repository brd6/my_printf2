/*
** main.c for my_printf in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun 25 21:10:21 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 21:17:03 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		main()
{
  int		i;

  i = my_printf("abc %s\n", "abc");
  my_printf("i=%d\n", i);
  return (0);
}
