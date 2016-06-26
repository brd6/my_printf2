/*
** printf_my_strcpy.c for printf_my_strcpy in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 17:04:50 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 17:06:59 2016 Berdrigue Bongolo-Beto
*/

char		*printf_my_strcpy(const char *src, char *str)
{
  int		i;

  i = 0;
  while (src && src[i])
    {
      str[i] = src[i];
      i++;
    }
  return (str);
}
