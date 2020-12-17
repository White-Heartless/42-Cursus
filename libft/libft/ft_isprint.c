#include "libft.h"

/*
*extracts and integer from a string
*/

int	ft_isprint(int character)
{
	unsigned char c;

	c = (unsigned char)character;
	if (c >= 32 && c <= 126)
		return (1);
	else
		return(0);
}

