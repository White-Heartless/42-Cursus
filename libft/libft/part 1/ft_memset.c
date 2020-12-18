#include "../libft.h"

// Fills a block of memory with the given character up to n bytes
// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting
//         from ptr to be filled

void	*ft_memset(void *ptr, int x, size_t n)
{
	unsigned char *address;

	address = (unsigned char*)ptr;
	while (n-- > 0)
		*address++ = (unsigned char)x;
	return (ptr);
}
