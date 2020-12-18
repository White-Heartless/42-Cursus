#include "../libft.h"

/*
*extracts and integer from a string
*/

int	ft_isdigit(int character)
{
	unsigned char c;

	c = (unsigned char)character;
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return(0);
}

