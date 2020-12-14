#include "libft.h"

/*
*Takes string source and copies it into destination,
*including the null character.
*Note: When you use strcpy(),
*the size of the destination string should be large enough to store the copied string.
*Otherwise, it may result in undefined behavior.
*/

char *ft_strcpy(char* destination, const char* source)
{
	int i;

	i = 0;
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = 0;
	return (destination);
}
