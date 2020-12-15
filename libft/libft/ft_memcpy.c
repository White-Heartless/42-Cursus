#include "libft.h"

// Copies n characters from memory area source to
// memory area dest

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char*)dest;
	source = (const unsigned char*)src;
	while (n--)
		*destination++ = *source++;
	return (dest);
}
