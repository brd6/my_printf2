/*
** printf_nbr_len.c for printf_nbr_len in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 20:38:45 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 20:38:47 2016 Berdrigue Bongolo-Beto
*/

int		printf_nbr_len(int nb)
{
  int		i;

  i = !nb;
  if (nb < 0)
    {
      i = i + 1;
      nb = nb * (-1);
    }
  while (nb > 0)
    {
      nb = (nb / 10);
      i++;
    }
  return (i);
}
