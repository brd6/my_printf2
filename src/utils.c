/*
** utils.c for utils in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 01:20:02 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 01:41:26 2016 Berdrigue Bongolo-Beto
*/

void		skip_char(const char *str, int *i, char c)
{
  while (str[*i] && str[*i] == c)
    *i = *i + 1;
}

int		is_alpha(char c, int flag)
{
  if (flag == 0)
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
  else if (flag == 1)
    return (c >= 'a' && c <= 'z');
  else if (flag == 2)
    return (c >= 'A' && c <= 'Z');
}

int		is_num(char c, int flag)
{
  char		b;

  b = (flag) ? '1' : '0';
  return (c >= b && c <= '9');
}

int		getchar_pos(const char *str, char c)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}
