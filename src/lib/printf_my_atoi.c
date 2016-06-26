/*
** printf_my_atoi.c for printf_my_atoi in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:32:06 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 20:33:56 2016 Berdrigue Bongolo-Beto
*/

int		printf_my_atoi(const char *nbr)
{
  int		i;
  int		res;

  res = 0;
  i = 0;
  while (nbr[i] >= '0' && nbr[i] <= '9')
    {
      res = res * 10 + nbr[i] - 48;
      i = i + 1;
    }
  return (res);
}
