/*
** malloc.h for malloc in /home/escorn_t/Rendu/PSU/test
** 
** Made by escorn_t
** Login   <thomas.escorne@epitech.eu>
** 
** Started on  Fri Jan 27 12:25:00 2017 escorn_t
** Last update Thu Feb  2 15:04:17 2017 Thomas Escorne
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <pthread.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct		s_block
{
  size_t       		size;
  bool			free;
  struct s_block        *prev;
  struct s_block       	*next;
}			t_block;

t_block *find_free(size_t size);
void    *first_alloc(size_t size);
void    *split_block(t_block *b, size_t size);
void    *expand(size_t size);
void    show_alloc_mem();
void    *malloc(size_t size);
void    free(void *ptr);
t_block *get_block(void *ptr);
size_t  align(size_t a);
void    *p_malloc(size_t);
void    p_free(void *ptr);
void    show_alloc_mem();
void    set_lock();
void    unlock();

# define METASIZE (sizeof(t_block))

#endif
