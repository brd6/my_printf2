/*
** print_str_large.c for print_str_large in /home/bongol_b/tmp/my_printf2/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Thu Jul  7 23:46:21 2016 Berdrigue Bongolo-Beto
** Last update Fri Jul  8 00:12:26 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

static int	is_printable(char c)
{
  return (c >= ' ' && c <= '~');
}

static int	print_mod_str(char *s, char *str)
{
  int		cp;
  int		i;
  t_print_elem	elem;
  char		*s2;
  char		*s3;

  i = 0;
  cp = 0;
  elem.buff[1] = 0;
  while (s && s[i])
    {
      if (!is_printable(s[i]))
	{
	  elem.buff[0] = '\\';
	  cp += check_print_limit_size(str, elem.buff);
	  cp += print_nchar('0', 3 - printf_nbr_len(s[i]), str);
	  s2 = printf_my_itoa(s[i]);
	  s3 = printf_convert_base(s2, BASE_DECIMAL, BASE_OCTAL);
	  cp += check_print_limit_size(str, s3);
	}
      else
	{
	  elem.buff[0] = s[i];
	  cp += check_print_limit_size(str, elem.buff);
	}
      i++;
    }
  return (cp);
}

int		print_str_large(char *str, va_list ap, t_ptf_format *format)
{
  char		*s;
  int		cp;

  s = printf_my_strdup((char *)va_arg(ap, char *));
  if (s == NULL)
    s = printf_my_strdup(STR_NULL_FLG);
  cp += print_mod_str(s);
  return (cp);
}
