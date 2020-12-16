#include "libft.h"

// Copies n characters from memory area source to
// memory area dest

// will generate issues if the memory blocks overlap.
// memmove solves this issue

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	while (n--)
		*destination++ = *source++;
	return (dest);
}
