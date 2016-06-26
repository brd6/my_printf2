/*
** my_printf.h for my_printf in /home/bongol_b/ProjetsPerso/my_printf/src
**
** Made by Berdrigue Bongolo-Beto
** Login   <bongol_b@epitech.net>
**
** Started on  Sat Jun 25 21:30:03 2016 Berdrigue Bongolo-Beto
** Last update Sun Jun 26 20:57:02 2016 Berdrigue Bongolo-Beto
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# define FD_ERROR		2
# define FD_OUT			1

# define NO_SIZE_FLG		-1
# define NO_FD_FLG		-1

# define IS_SNPRINTF		2
# define IS_SPRINTF		1
# define IS_PRINTF		-1

# define ALLOW_FORMAT		"diouxXcsSpnb-+*.hl#%"
# define MY_PRINTF_TAB_SIZE	12

# include <stddef.h>
# include <stdarg.h>

typedef struct	s_ptf_format
{
  char		flags[3];
  char		*field_width;
  char		*precision;
  char		length_modifier;
  char		conv_char;
}		t_ptf_format;

typedef struct	s_printf
{
  char		type;
  int		(*func)(char *str, va_list ap, t_ptf_format *format);
}		t_printf;

typedef struct	s_prog
{
  int		is_sprintf;
  int		fd;
  int		size_limit;
  int		i;
}		t_prog;

extern t_prog	g_prog;

int		global_handler(char *str,
			       const char *format,
			       va_list ap,
			       t_printf *tab);
int		sprintf_handler(char *str,
				int fd,
				const char *format,
				...);
int		printf_handler(int fd,
			       const char *format,
			       ...);

/*
** Printfs
*/
# define my_printf(format, ...) printf_handler(FD_OUT, format, ##__VA_ARGS__)
# define my_eprintf(format, ...) printf_handler(FD_ERROR, format, ##__VA_ARGS__)
# define my_dprintf(fd, format, ...) printf_handler(fd, format, ##__VA_ARGS__)
# define my_sprintf(str, format, ...) sprintf_handler(str,		\
						      NO_SIZE_FLG,	\
						      format,		\
						      ##__VA_ARGS__)
# define my_snprintf(str, size, format, ...) sprintf_handler(str,	\
							     size,	\
							     format,	\
							     ##__VA_ARGS__)

void		init_printf_var(t_printf *tab);
void		init_prog(int fd, int flag);
int		init_ptf_format(const char *format,
				int *i,
				t_ptf_format *ptf_format);

/*
** Printf utils
*/
int		check_format(const char *str);
int		check_next_char(const char *format);
void		set_width(int *width,
			  t_ptf_format *ptf_format,
			  va_list ap);
int		set_prec_len(int *len, t_ptf_format *ptf_format, va_list ap);
void		check_width(int *width, int cp);
void		check_width_and_precision(int *wd,
					  int *lp,
					  int nbr,
					  t_ptf_format *ptf_f);
void		check_width_and_precision2(int *wd,
					   int *lp,
					   char *s,
					   t_ptf_format *ptf);

int		print_nil(char *str, va_list ap, t_ptf_format *format);
int		print_nbr(char *str, va_list ap, t_ptf_format *format);
int		print_char(char *str, va_list ap, t_ptf_format *format);

/*
** Utils
*/
int		is_num(char c, int flag);
int		is_alpha(char c, int flag);
void		skip_char(const char *str, int *i, char c);
int		getchar_pos(const char *str, char c);
int		print_nchar(char c, int n);

/*
** Lib
*/
int		printf_my_strlen(const char *s);
char		*printf_my_strdup(const char *s);
char		*printf_my_getstr(const char *s, int (*cmp)(char));
char		*printf_my_itoa(int nbr);
char		*printf_my_strcpy(const char *src, char *str);
int		printf_my_putstr(int fd, const char *s);
int		printf_my_putchar(int fd, char c);
int		printf_my_atoi(const char *nbr);
int		printf_nbr_len(int nb);

#endif /* !MY_PRINTF_H_ */
