#include "../libft.h"

/*
*extracts and integer from a string
*/

void	*ft_memalloc(size_t amount)
{
	void	*address;

	address = (void *)malloc(amount);
	if (address == NULL)
		return (NULL);
	else
	{
		ft_memset(address,0,amount);
		return (address);
	}
}
