#include "../libft.h"

/*
*when passed and uppercase alphabet, returns its lowercase
*/

int	ft_tolower(int character)
{
	unsigned char c;

	c = (unsigned char)character;
	if ((c >= 'A' && c <= 'Z'))
		return (c + 32);
	else
		return(character);
}

