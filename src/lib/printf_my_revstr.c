/*
** printf_my_revstr.c for printf_my_revstr in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Jul  4 21:23:31 2016 Berdrigue Bongolo-Beto
** Last update Mon Jul  4 21:27:02 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

static void	str_swap(char *a, char *b)
{
  char		*tmp;

  tmp = a;
  a = b;
  b = tmp;
}

char		*printf_my_revstr(char *s)
{
  int		i;
  int		len;

  i = 0;
  len = printf_my_strlen(s);
  while (i < len / 2)
    {
      str_swap(&s[i], &s[len - i - 1]);
      i++;
    }
  return (s);
}
