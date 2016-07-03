/*
** utils2.c for utils2 in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:56:00 2016 Berdrigue Bongolo-Beto
** Last update Sun Jul  3 14:03:19 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		print_nchar(char c, int n, char *str)
{
  int		i;

  i = 0;
  while (i < n)
    {
      if (str == NULL)
	i += printf_my_putchar(g_prog.fd, c);
      else
	{
	  str[g_prog.i++] = c;
	  i++;
	}
    }
  n = (n < 0) ? 0 : n;
  if (str == NULL)
    g_prog.i += n;
  return (n);
}

int		nbr_space_handler(t_ptf_format *format,
				  int nbr,
				  t_print_elem *elem,
				  char *str)
{
  elem->buff[1] = 0;
  elem->buff[0] = ' ';
  if (getchar_pos(format->flags, ' ') != -1 && nbr > 0)
    return (check_print_limit_size(str, elem->buff));
  return (0);
}
