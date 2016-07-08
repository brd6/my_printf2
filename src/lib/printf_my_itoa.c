/*
** printf_my_itoa.c for printf_my_itoa in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 13:13:18 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:20:05 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static void	recurr_itoa(char *str, int  nbr, int *i)
{
  if (nbr >= 0 && nbr <= 9)
    {
      str[*i] = nbr + '0';
      *i = *i + 1;
    }
  else if (nbr > 9)
    {
      recurr_itoa(str, nbr / 10, i);
      recurr_itoa(str, nbr % 10, i);
    }
}

char		*printf_my_itoa(int nbr)
{
  char		*str;
  int		i;

  if ((str = malloc(sizeof(*str) * (printf_nbr_len(nbr) + 2))) == NULL)
    return (NULL);
  i = 0;
  if (nbr < 0)
    {
      str[i] = '-';
      i = i + 1;
      nbr = nbr * (-1);
    }
  recurr_itoa(str, nbr, &i);
  str[i] = 0;
  return (str);
}
