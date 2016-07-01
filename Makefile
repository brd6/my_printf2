##
## Makefile for my_printf in /home/bongol_b/ProjetsPerso/my_printf
## 
## Made by Berdrigue Bongolo-Beto
## Login   <bongol_b@epitech.net>
## 
## Started on  Sat Jun 25 21:07:14 2016 Berdrigue Bongolo-Beto
## Last update Sat Jul  2 00:17:52 2016 Berdrigue Bongolo-Beto
##

CC		= 	gcc -g3

RM		= 	rm -f

AR		=	ar cr

RAN		=	ranlib

TEST_NAME	= 	test

NAME		=	my_printf.a

ROOT_DIRECTORY	=	src


PRINT_SRCS	=	$(ROOT_DIRECTORY)/print/print_nil.c \
			$(ROOT_DIRECTORY)/print/print_nbr.c \
			$(ROOT_DIRECTORY)/print/print_char.c \
			$(ROOT_DIRECTORY)/print/print_percent.c \
			$(ROOT_DIRECTORY)/print/utils.c \
			$(ROOT_DIRECTORY)/print/utils2.c \

MINILIB_SRCS	=	$(ROOT_DIRECTORY)/lib/printf_my_strdup.c \
			$(ROOT_DIRECTORY)/lib/printf_my_strlen.c \
			$(ROOT_DIRECTORY)/lib/printf_my_getstr.c \
			$(ROOT_DIRECTORY)/lib/printf_my_itoa.c \
			$(ROOT_DIRECTORY)/lib/printf_my_strcpy.c \
			$(ROOT_DIRECTORY)/lib/printf_my_putchar.c \
			$(ROOT_DIRECTORY)/lib/printf_my_putstr.c \
			$(ROOT_DIRECTORY)/lib/printf_my_atoi.c \
			$(ROOT_DIRECTORY)/lib/printf_nbr_len.c \

SRCS		= 	$(ROOT_DIRECTORY)/printf_handler.c \
			$(ROOT_DIRECTORY)/sprintf_handler.c \
			$(MINILIB_SRCS) \
			$(PRINT_SRCS) \
			$(ROOT_DIRECTORY)/global_handler.c \
			$(ROOT_DIRECTORY)/init_printf.c \
			$(ROOT_DIRECTORY)/init_format.c \
			$(ROOT_DIRECTORY)/printf_handler_util.c \
			$(ROOT_DIRECTORY)/utils.c \

TEST_SRCS	=	$(ROOT_DIRECTORY)/main.c \
			$(SRCS)

OBJS		= 	$(SRCS:.c=.o)

TEST_OBJS	= 	$(TEST_SRCS:.c=.o)

#CFLAGS		+=	-W -Wall -Wextra -Werror

CFLAGS		+=	-I./include/

LDFLAGS +=	-L./ -lmy_printf

all: $(NAME) test

$(NAME): $(OBJS)
	@$(AR) $(LIBNAME) $(OBJS)
	@$(RAN) $(LIBNAME)

test: $(TEST_OBJS)
	$(CC) $(TEST_OBJS) -o $(TEST_NAME) #$(LDFLAGS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(TEST_OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(TEST_NAME)

re: fclean all

.PHONY: clean, re, all, fclean
