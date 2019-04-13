/*
** free.c for PSU_2016_malloc in /home/osborn_s/Tek_2/PSU/PSU_2016_malloc/test
** 
** Made by Osborne Samuel
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Jan 31 19:47:14 2017 Osborne Samuel
** Last update Tue Feb  7 11:38:14 2017 Osborne Samuel
*/

#include "malloc.h"

extern t_block			*head;

t_block		*get_block(void *ptr)
{
  char          *tmp;

  tmp = ptr;
  return (ptr = tmp - METASIZE);
}

t_block		*merge_free_blocks(t_block *block)
{
  t_block	*tmp;

  tmp = block;
  while (tmp->next && tmp->next->free == 1)
    {
      tmp->size += METASIZE + tmp->next->size;
      tmp->next = tmp->next->next;
      if (tmp->next)
	tmp->next->prev = tmp;
    }
  return (tmp);
}

int		is_last(t_block *block)
{
  t_block	*tmp;
  int		stock;

  stock = 0;
  tmp = block;
  while (tmp)
    {
      if (tmp->free == 0)
	{
	  return (0);
	}
      stock += METASIZE + tmp->size;
      tmp = tmp->next;
    }
  return (stock);
}

void		truncate_heap(t_block *block)
{
  if (block->next)
    return ;
  if (block->prev)
    block->prev->next = NULL;
  else
    head = NULL;
  sbrk(-1 * (block->size + METASIZE));
}

void		p_free(void *ptr)
{
  t_block       *toFree;
  void          *tmp;

  tmp = get_block(ptr);
  toFree = tmp;
  if (toFree < head || tmp > sbrk(0))
    return ;
  toFree->free = 1;
  toFree = merge_free_blocks(toFree);
  truncate_heap(toFree);
}
