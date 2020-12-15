#include "libft.h"

// Copies n characters from memory area source to
// memory are dest

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t			i;

	i = 0;
	destination = (unsigned char*)dest;
	source = (const unsigned char*)src;
	while (n--)
		*destination++ = *source++;
	return (dest);
}
