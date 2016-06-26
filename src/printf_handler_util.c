/*
** printf_handler_util.c for printf_handler_util in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 01:16:22 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 13:56:45 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

int		check_format(const char *str)
{
  int		i;


  i = 0;
  while ((str && str[i]) &&
	 (str[i] != '%' && is_num(str[i], 0) && !is_alpha(str[i], 0)))
    {
      if (str[i] != ' ')
	return (0);
      i++;
    }
  return (1);
}

int		check_next_char(const char *format)
{
  int   i;

  i = 0;
  skip_char(format, &i, ' ');
  if (getchar_pos(ALLOW_FORMAT, format[i]) != -1 ||
      is_num(format[i], 0))
    return (1);
  return (0);
}
