#include "../libft.h"

/*
*extracts and integer from a string.
*/

int	ft_isascii(int character)
{
	if (character >= 0 && character <= 127)
		return (character);
	else
		return(0);
}

