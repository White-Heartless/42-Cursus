#include "../libft.h"

/*
*Takes string source and concatenates up to n chars from it
*after the end of destination, replacing the '\0' in destination,
*and adding the '\0' from the source at the end.
*dest HAS to be big enough to contain n chars + 1, or you will segfault
*/

char *ft_strncat(char* dest, const char* src, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && n)
	{
		dest[i] = src[j];
		j++;
		i++;
		n--;
	}
	return (dest);
}

