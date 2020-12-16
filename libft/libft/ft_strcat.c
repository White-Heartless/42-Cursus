#include "libft.h"

/*
*Takes string source and concatenates it
*after the end of destination, replacing the '\0' in destination,
*and adding the '\0' from the source at the end, if present
*dest HAS to be big enough to contain src, or you will segfault
*/

char *ft_strcat(char* dest, const char* src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (src[i] == 0)
		dest[i] = 0;
	return (dest);
}

