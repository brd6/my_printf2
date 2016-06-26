/*
** printf_my_strlen.c for printf_my_strlen in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 12:20:50 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 12:21:18 2016 Berdrigue Bongolo-Beto
*/

int		printf_my_strlen(const char *s)
{
  int		i;

  i = 0;
  while (s && s[i])
    i++;
  return (i);
}
