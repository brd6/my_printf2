/*
** main.c for my_printf in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun 25 21:10:21 2016 Berdrigue Bongolo-Beto
** Last update Wed Jul  6 21:13:20 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

int		main()
{
  char		*s;
  char		buff[100];
  int		ret;
  int		n;

  s = NULL;
  buff[0] = 0;
  /* ret = my_printf("abc %c ok", 'c'); */
  /* ret = my_printf("'azc '%+3d''", 1); */
  /* printf("\nret: %d '%s'\n", ret, buff); */

  /* ret = printf("'azc '%+3d''", 1); */
  /* printf("\nret: %d '%s'\n", ret, buff); */

  ret = my_printf("'azc '%X'' %n", 1201, &n);
  printf("\nret: %d '%s' n=%d\n", ret, buff, n);

  ret = printf("'azc '%X'' %n", 1201, &n);
  printf("\nret: %d '%s' n=%d\n", ret, buff, n);


  /* ret = printf("abc %c ok", 'c'); */
  /* ret = snprintf(buff, 0, "abc %c ok", 'c'); */
  /* printf("ret: %d '%s'\n", ret, buff); */
  return (EXIT_SUCCESS);
}
