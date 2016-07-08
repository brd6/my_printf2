/*
** printf_my_strcpy.c for printf_my_strcpy in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 17:04:50 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 20:09:27 2016 Berdrigue Bongolo-Beto
*/

char		*printf_my_strcpy(char *dest, const char *src)
{
  int		i;

  i = 0;
  while (src && src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = 0;
  return (dest);
}
