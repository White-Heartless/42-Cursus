#include "../libft.h"

/*
*allocates amount bytes of memory and returns a pointer
*to the memory area created
*/

void	*ft_memalloc(size_t amount)
{
	void	*address;

	address = (void *)malloc(amount);
	if (address == NULL)
		return (NULL);
	ft_memset(address,0,amount);
	return (address);
}
