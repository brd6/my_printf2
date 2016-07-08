/*
** printf_convert_base.c for printf_convert_base in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Jul  4 20:50:39 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:35:46 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static int	set_sign(char *s, int *neg, int *i, int flag)
{
  if (flag)
    {
      if (*neg == 1)
	{
	  s[*i] = '-';
	  *i = *i + 1;
	}
    }
  else
    {
      *neg = 1;
      return (1);
    }
  return (0);
}

static char	*return_zero_base(const char *base)
{
  char		*s;

  if ((s = malloc(sizeof(*s) + 2)) == NULL)
    return (NULL);
  s[0] = base[0];
  s[1] = 0;
  return (s);
}

char		*printf_convert_base(const char *nbr,
				     const char *base_from,
				     const char *base_to)
{
  char		*s;
  int		i;
  int		neg;
  int		j;
  int		nbr_base;
  int		base_to_len;

  i = printf_my_strlen(base_to) + printf_my_strlen(base_from);
  j = 0;
  neg = 0;
  if ((s = malloc(sizeof(*s) * (printf_my_strlen(nbr) + i + 1))) == NULL)
    return (NULL);
  i = 0;
  if (nbr[i] == '-' && set_sign(s, &neg, &i, 0) == 1)
    j = 1;
  nbr_base = printf_my_getnbr_base((const char *)nbr + j, base_from);
  if (nbr_base == 0 || (base_to_len = printf_my_strlen(base_to)) == 0)
    return (return_zero_base(base_to));
  while (nbr_base > 0)
    {
      s[i++] = base_to[nbr_base % base_to_len];
      nbr_base = nbr_base / base_to_len;
    }
  set_sign(s, &neg, &i, 1);
  s[i] = 0;
  return (printf_my_revstr(s));
}
