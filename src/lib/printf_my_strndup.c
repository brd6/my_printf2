/*
** printf_my_strndup.c for printf_my_strndup in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Jul  4 20:24:24 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:48:50 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

char		*printf_my_strndup(const char *s, int n)
{
  char		*ret;
  int		i;

  n = (n < 1) ? printf_my_strlen(s) : n;
  if (s == NULL || (ret = malloc(sizeof(*s) * (n + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s && s[i] && i < n)
    {
      ret[i] = s[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
