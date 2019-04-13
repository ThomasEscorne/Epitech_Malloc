/*
** multi_thread.c for PSU_2016_malloc in /home/osborn_s/Tek_2/PSU/PSU_2016_malloc
** 
** Made by Osborne Samuel
** Login   <osborn_s@epitech.net>
** 
** Started on  Tue Jan 31 12:38:12 2017 Osborne Samuel
** Last update Wed Feb  1 09:05:23 2017 Osborne Samuel
*/

#include "malloc.h"

static pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

void	set_lock()
{
  pthread_mutex_lock(&mutex);
}

void	unlock()
{
  pthread_mutex_unlock(&mutex);
}
