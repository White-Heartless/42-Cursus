#include "libft.h"

/*
*Takes a string as input and returns the length of the string,
*excluding the terminator character.
*/
size_t ft_strlen(const char *string)
{
	size_t length;

	length = 0;
	while (string[length])
		length++;
	return (length);
}
