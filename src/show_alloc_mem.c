/*
** tmp_alloc_mem.c for malloc in /home/escorn_t/Rendus/PSU/PSU_2016_malloc
** 
** Made by Thomas Escorne
** Login   <escorn_t@epitech.net>
** 
** Started on  Tue Jan 31 09:29:19 2017 Thomas Escorne
** Last update Wed Feb  1 16:15:58 2017 escorn_t
*/

#include <unistd.h>
#include "malloc.h"

extern t_block	*head;

void		print_hexa(size_t nb, int div)
{
  char		c;

  c = 0;
  if (nb)
    {
      print_hexa(nb / div, div);
      if (nb % div < 10)
	c = (nb % div) + 48;
      else
	c = (nb % div) + 55;
      write(1, &c, 1);
    }
}

void		print_break()
{
  write(1, "break : 0x", 10);
  print_hexa(((size_t)sbrk(0)), 10);
  write(1, "\n", 1);
}

void		print_bytes(void *add1, void *add2, size_t size)
{
  write(1, "0x", 2);
  print_hexa(((size_t)add1), 16);
  write(1, " - 0x", 5);
  print_hexa(((size_t)add2), 16);
  write(1, " : ", 5);
  print_hexa(size, 10);
  write(1, " bytes\n", 7);
}

void		show_alloc_mem()
{
  t_block       *tmp;

  tmp = head;
  print_break();
  while (tmp)
    {
      if (tmp->free == 0)
	{
	  if (tmp->next)
	    print_bytes((void *)tmp + METASIZE, (void *)tmp->next, tmp->size);
	  else
	    print_bytes((void *)tmp + METASIZE, sbrk(0), tmp->size);
	}
      tmp = tmp->next;
    }
}
