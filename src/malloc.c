/*
** malloc.c for malloc in /home/escorn_t/Rendu/PSU/test
** 
** Made by escorn_t
** Login   <thomas.escorne@epitech.eu>
** 
** Started on  Fri Jan 27 12:27:26 2017 escorn_t
** Last update Sat Feb 11 17:15:01 2017 escorn_t
*/

#include "malloc.h"

extern t_block		*head;

size_t		align(size_t a)
{
  if (a == 0)
    return (8);
  return (a / 8 * 8 + 8);
}

void		*first_alloc(size_t size)
{
  size_t	s;
  void		*sec;

  s = getpagesize() * (1 + ((size + 2 * METASIZE) / getpagesize()));
  if (s < size + METASIZE)
    return (NULL);
  if ((head = sbrk(s)) == (void *)-1)
    return (NULL);
  head->size = size;
  head->free = 0;
  head->prev = NULL;
  sec = (char *)head + size + METASIZE;
  head->next = (t_block *)sec;
  ((t_block *)sec)->size = s - (2 * METASIZE) - size;
  ((t_block *)sec)->free = 1;
  ((t_block *)sec)->prev = head;
  ((t_block *)sec)->next = NULL;
  return ((char *)head + METASIZE);
}

t_block		*find_free(size_t size)
{
  t_block	*tmp;

  tmp = head;
  while (tmp)
    {
      if (tmp->free == 1 && tmp->size > size + METASIZE)
	{
	  return (tmp);
	}
      tmp = tmp->next;
    }
  return (tmp);
}

void		*split_block(t_block *b, size_t size)
{
  void		*new;

  b->free = 0;
  if (b->size <= (2 * METASIZE) + size)
    {
      return ((void *)b + METASIZE);
    }
  new = (void *)b + METASIZE + size;
  ((t_block *)new)->size = b->size - METASIZE - size;
  ((t_block *)new)->free = 1;
  ((t_block *)new)->next = b->next;
  ((t_block *)new)->prev = b;
  b->size = size;
  b->next = (t_block *)new;
  return ((char *)b + METASIZE);
}

void		*expand(size_t size)
{
  t_block	*tmp;
  t_block	*new;
  void		*sec;
  size_t       	s;

  tmp = head;
  while (tmp->next)
    tmp = tmp->next;
  s = getpagesize() * (1 + ((size + 2 * METASIZE) / getpagesize()));
  if (s < size + METASIZE)
    return (NULL);
  if ((new = sbrk(s)) == (void *)-1)
    return (NULL);
  tmp->next = new;
  new->prev = tmp;
  new->size = size;
  new->free = 0;
  sec = (void *)new + size + METASIZE;
  new->next = sec;
  ((t_block *)sec)->size = s - (2 * METASIZE) - size;
  ((t_block *)sec)->free = 1;
  ((t_block *)sec)->next = NULL;
  ((t_block *)sec)->prev = new;
  return ((void *)new + METASIZE);
}
