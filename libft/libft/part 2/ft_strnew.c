#include "../libft.h"

/*
*allocates a new string of amount chars
*allocates every byte of the created string to 0
*and returns a pointer to the string created
*/

char	*ft_strnew(size_t amount)
{
	return ((char *)ft_memalloc(amount + 1));
}

