/*
** my_printf.c for my_printf in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun 25 21:32:26 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 19:39:38 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

t_prog		g_prog;

int		printf_handler(int fd,
			       const char *format,
			       ...)
{
  va_list	ap;
  t_printf	tab[MY_PRINTF_TAB_SIZE];

  init_printf_var(tab);
  init_prog(fd, IS_PRINTF);
  va_start(ap, format);
  global_handler(NULL, format, ap, tab);
  va_end(ap);
  return (g_prog.i);
}
