/*
** printf_my_getnbr_base.c for printf_my_getnbr_base in /home/bongol_b/ProjetsPerso/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Mon Jul  4 21:06:49 2016 Berdrigue Bongolo-Beto
** Last update Mon Jul  4 21:31:27 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

static int	get_sign(const char *str, int *nbr_pos)
{
  int		i;
  int		sign;

  i = 0;
  sign = 1;
  while (str[i] == '+' || str[i] == '-')
    {
      if (str[i] == '-')
	sign = sign * (-1);
      i++;
    }
  *nbr_pos = i;
  return (sign);
}

int		printf_my_getnbr_base(const char *str, const char *base)
{
  int		res;
  int		sign;
  int		j;
  int		base_len;
  int		i;

  j = 0;
  base_len = printf_my_strlen(base);
  res = 0;
  i = 0;
  sign = get_sign(str, &i);
  while (str && str[i])
    {
      while (j <= base_len && str && str[i] != base[j])
	j++;
      if (str[i] == base[j])
	res = res * base_len + j;
      j = 0;
      i++;
    }
  return (res *sign);
}
