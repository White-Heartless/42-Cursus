#include "../libft.h"

// Copies characters from memory area source to
// memory area dest until it encouters
// character c or until it has copied n bytes,
// whichever comes first

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;

	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	while (n--)
	{
		*destination = *source;
		if (*source == (unsigned char)c)
			return (destination + 1);
		destination++;
		source++;
	}
	return (NULL);
}
