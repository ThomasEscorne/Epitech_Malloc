/*
** calloc.c for PSU_2016_malloc in /home/osborn_s/Tek_2/PSU/PSU_2016_malloc/test
** 
** Made by Osborne Samuel
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Jan 31 18:56:35 2017 Osborne Samuel
** Last update Thu Feb  9 17:17:23 2017 Samuel Osborne
*/

#include <string.h>
#include "malloc.h"

void		*calloc(size_t nbr, size_t size)
{
  void		*block;
  size_t	sum;

  sum = size * nbr;
  if (sum + METASIZE >= (size_t)-1)
    return (NULL);
  if ((block = malloc(sum)) == NULL)
    return (NULL);
  memset(block, 0, sum);
  return (block);
}
