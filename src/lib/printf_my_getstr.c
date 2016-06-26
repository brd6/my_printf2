/*
** printf_my_getstr.c for printf_my_getstr in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 12:37:33 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 12:50:49 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>

static int	count_str(const char *s, int (*cmp)(char))
{
  int		i;

  i = 0;
  while (s && cmp(s[i]))
    i++;
  return (i);
}

char		*printf_my_getstr(const char *s, int (*cmp)(char))
{
  char		*ret;
  int		i;

  if ((ret = malloc(sizeof(*s) * (count_str(s, cmp) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s && cmp(s[i]))
    {
      ret[i] = s[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
