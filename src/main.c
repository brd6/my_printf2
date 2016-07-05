/*
** main.c for my_printf in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun 25 21:10:21 2016 Berdrigue Bongolo-Beto
** Last update Tue Jul  5 20:50:57 2016 Berdrigue Bongolo-Beto
*/

#include <stdlib.h>
#include "my_printf.h"

int		main()
{
  char		*s;
  char		buff[100];
  int		ret;

  s = NULL;
  buff[0] = 0;
  /* ret = my_printf("abc %c ok", 'c'); */
  /* ret = my_printf("'azc '%+3d''", 1); */
  /* printf("\nret: %d '%s'\n", ret, buff); */

  /* ret = printf("'azc '%+3d''", 1); */
  /* printf("\nret: %d '%s'\n", ret, buff); */

  ret = my_printf("'azc '%u''", 1201);
  printf("\nret: %d '%s'\n", ret, buff);

  ret = printf("'azc '%u''", 1201);
  printf("\nret: %d '%s'\n", ret, buff);


  /* ret = printf("abc %c ok", 'c'); */
  /* ret = snprintf(buff, 0, "abc %c ok", 'c'); */
  /* printf("ret: %d '%s'\n", ret, buff); */
  return (EXIT_SUCCESS);
}
