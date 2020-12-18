#include "../libft.h"

/*
*when passed a lowercase alphabet, returns its uppercase
*/

int	ft_toupper(int character)
{
	unsigned char c;

	c = (unsigned char)character;
	if ((c >= 'a' && c <= 'z'))
		return (c - 32);
	else
		return(character);
}

