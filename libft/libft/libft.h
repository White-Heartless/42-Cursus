#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *ptr, int x, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *str);
char*	ft_strcpy(char* destination, const char* source);

# endif // LIBFT_H
