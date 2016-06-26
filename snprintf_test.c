/*
** snprintf_test.c for  in /home/bongol_b/ProjetsPerso/my_printf
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sun Jun 26 14:31:22 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 15:58:19 2016 Berdrigue Bongolo-Beto
*/

#include <stdio.h>

int		main()
{
  char		buff[100];
  int		ret;

  ret = snprintf(buff, -2, "a    %s b\n", "Hellob");
  printf("ret: %d\nbuff: '%s'\n", ret, buff);
}
