/*
** realloc.c for PSU_2016_malloc in /mnt/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/osborn_s/Tek_2/PSU/PSU_2016_malloc
** 
** Made by Samuel Osborne
** Login   <samuel.osborne@epitech.eu>
** 
** Started on  Mon Jan 30 13:19:42 2017 Samuel Osborne
** Last update Wed Feb  1 10:24:21 2017 Thomas Escorne
*/

#include <string.h>
#include "malloc.h"

extern t_block	*head;

void		*p_realloc(void *ptr, size_t s)
{
  t_block	*oldB;
  void		*newP;

  oldB = get_block(ptr);
  if (ptr > sbrk(0) || oldB < head)
    return (NULL);
  if (ptr == NULL && s != 0)
    {
      if ((newP = p_malloc(s)) == NULL)
	return (NULL);
      return (newP);
    }
  else if (s == 0 && ptr != NULL)
    {
      p_free(ptr);
      return (NULL);
    }
  if ((newP = p_malloc(s)) == NULL)
    return (NULL);
  newP = memmove(newP, ptr, s);
  p_free(ptr);
  return (newP);
}

void		*realloc(void *ptr, size_t s)
{
  void		*res;

  set_lock();
  res = p_realloc(ptr, s);
  unlock();
  return (res);
}
