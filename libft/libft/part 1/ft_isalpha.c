#include "../libft.h"

/*
*extracts and integer from a string
*/

int	ft_isalpha(int character)
{
	unsigned char c;

	c = (unsigned char)character;
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return(0);
}
