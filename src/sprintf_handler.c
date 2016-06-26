/*
** sprintf_handler.c for sprintf_handler in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 10:50:31 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 19:39:28 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

t_prog		g_prog;

int		sprintf_handler(char *str,
				int fd,
				const char *format,
				...)
{
  va_list	ap;
  t_printf	tab[MY_PRINTF_TAB_SIZE];

  init_printf_var(tab);
  init_prog(fd, IS_SPRINTF);
  va_start(ap, format);
  global_handler(str, format, ap, tab);
  va_end(ap);
  return (g_prog.i);
}
