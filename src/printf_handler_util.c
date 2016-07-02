/*
** printf_handler_util.c for printf_handler_util in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 01:16:22 2016 Berdrigue Bongolo-Beto
** Last update Sat Jul  2 19:32:14 2016 Berdrigue Bongolo-Beto
*/

#include "my_printf.h"

/*
** To delete /!\
*/
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
  int		i;

  i = 0;
  skip_char(format, &i, ' ');
  if (getchar_pos(ALLOW_FORMAT, format[i]) != -1 ||
      is_num(format[i], 0))
    return (1);
  return (0);
}

int		check_print_limit_size(char *str, const char *s)
{
  int		check;
  int		len;

  check = ((g_prog.is_sprintf == IS_SNPRINTF &&
	    g_prog.i < g_prog.size_limit) ||
	   (g_prog.is_sprintf == IS_SPRINTF));
  if (str == NULL && s == NULL)
    return (check);
  if (check)
    printf_my_strcpy(s, &str[g_prog.i]);
  else
    printf_my_putstr(g_prog.fd, s);
  len = printf_my_strlen(s);
  g_prog.i += len;
  return (len);
}
