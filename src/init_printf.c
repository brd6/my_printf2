/*
** init_printf.c for init_printf in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 00:51:57 2016 Berdrigue Bongolo-Beto
** Last update Thu Jul  7 23:45:47 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

static void	init_each_tab(t_printf *tab,
			      char type,
			      int (*func)(char *str, va_list, t_ptf_format *))
{
  tab->type = type;
  tab->func = func;
}

void		init_prog(int fd, int flag)
{
  g_prog.i = 0;
  g_prog.fd = (flag == IS_PRINTF) ? fd : NO_FD_FLG;
  g_prog.size_limit = (g_prog.fd == NO_FD_FLG) ? (fd - 1) : NO_SIZE_FLG;
  g_prog.is_sprintf = (flag != IS_PRINTF);
  if (g_prog.is_sprintf && g_prog.size_limit >= 0)
    g_prog.is_sprintf = IS_SNPRINTF;
  else if (g_prog.is_sprintf)
    g_prog.is_sprintf = IS_SPRINTF;
}

void		init_printf_var(t_printf *tab)
{
  int		i;

  i = 0;
  init_each_tab(&tab[i++], 'i', &print_nbr);
  init_each_tab(&tab[i++], 'd', &print_nbr);
  init_each_tab(&tab[i++], 'c', &print_char);
  init_each_tab(&tab[i++], '%', &print_percent);
  init_each_tab(&tab[i++], 's', &print_str);
  init_each_tab(&tab[i++], 'o', &print_octal);
  init_each_tab(&tab[i++], 'u', &print_unsigned_nbr);
  init_each_tab(&tab[i++], 'x', &print_hexa);
  init_each_tab(&tab[i++], 'X', &print_hexa);
  init_each_tab(&tab[i++], 'p', &print_pointer);
  init_each_tab(&tab[i++], 'n', &print_ncount);
  init_each_tab(&tab[i++], 'b', &print_binary);
  init_each_tab(&tab[i++], 'S', &print_str_large);
  init_each_tab(&tab[i++], 0, NULL);
}
