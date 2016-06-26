/*
** printf_my_strdup.c for printf_my_strdup in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 12:19:57 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 12:53:58 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

char		*printf_my_strdup(const char *s)
{
  char		*ret;
  int		i;

  if ((ret = malloc(sizeof(*s) * (printf_my_strlen(s) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s && s[i])
    {
      ret[i] = s[i];
      i++;
    }
  ret[i] = 0;
  return (ret);
}
