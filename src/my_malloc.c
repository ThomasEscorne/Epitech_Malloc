/*
** my_malloc.c for malloc.c in /home/escorn_t/Rendu/PSU/test/src
** 
** Made by escorn_t
** Login   <thomas.escorne@epitech.eu>
** 
** Started on  Wed Feb  1 16:13:15 2017 escorn_t
** Last update Sat Feb 11 15:19:06 2017 escorn_t
*/

#include "malloc.h"

t_block		*head = NULL;

void		*p_malloc(size_t size)
{
  t_block       *tmp;

  size = align(size);
  if (head == NULL)
    return (first_alloc(size));
  tmp = find_free(size);
  if (tmp == NULL)
    return (expand(size));
  else
    return (split_block(tmp, size));
}

void		*malloc(size_t size)
{
  void          *res;

  if (size >= (size_t)-1 - (getpagesize() * (1 + ((size + 2 * METASIZE) / getpagesize()))))
    return (NULL);
  set_lock();
  res = p_malloc(size);
  unlock();
  return (res);
}

void		free(void *ptr)
{
  set_lock();
  p_free(ptr);
  unlock();
}
