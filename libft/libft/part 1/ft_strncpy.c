#include "../libft.h"

/*
*Takes string source and copies it into destination,
*including the null character.
*Note: When you use strncpy(),
*the size of the destination string should be large enough to store the copied string.
*Otherwise, it may result in undefined behavior.
*if source is >= n the 0 char wont be copied
*/

char *ft_strncpy(char* dest, const char* src, size_t n)
{
	int i;

	i = 0;
	while (n && src[i])
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	if (n > 0)
		dest[i] = src[i];
	return (dest);
}
