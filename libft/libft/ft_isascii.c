#include "libft.h"

/*
*extracts and integer from a string
*/

int	ft_isascii(int character)
{
	unsigned char c;

	c = (unsigned char)character;
	if (c >= 0 && c <= 127)
		return (1);
	else
		return(0);
}

