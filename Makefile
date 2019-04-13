##
## Makefile for PSU_2016_malloc in /media/samuel/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/osborn_s/Tek_2/PSU/PSU_2016_malloc
## 
## Made by Samuel Osborne
## Login   <samuel.osborne@epitech.eu>
## 
## Started on  Wed Jan 25 09:59:02 2017 Samuel Osborne
## Last update Thu Feb  9 15:46:53 2017 Osborne Samuel
##

SRC	=	src/malloc.c		\
		src/free.c		\
		src/realloc.c		\
		src/show_alloc_mem.c	\
		src/multi_thread.c	\
		src/calloc.c		\
		src/my_malloc.c

CC	=	gcc

RM	=	rm -f

NAME	=	libmy_malloc.so

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-fpic -W -Wall -Iinclude -std=gnu99

LDFLAGS	=	-shared

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
