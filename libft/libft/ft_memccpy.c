#include "libft.h"

// Copies characters from memory area source to
// memory area dest until it encouters
// character c or until it has copied n bytes,
// whichever comes first

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char*)dest;
	source = (const unsigned char*)src;
	while (n-- && *source != (unsigned char)c)
		*destination++ = *source++;
	if (n > 0 && *source == (unsigned char)c)
		*destination = *source;
	return (dest);
}
