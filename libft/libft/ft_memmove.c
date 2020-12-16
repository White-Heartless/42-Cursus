#include "libft.h"

// Copies n characters from memory area source to
// memory area dest

// this will not generate issues if the memory blocks overlap.
// unlike memcpy

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char*)dest;
	source = (unsigned char*)src;
	if (destination < source)
	{
		while (n--)
			*destination++ = *source++;
	}
	else
	{
		destination = (unsigned char*)dest + (n - 1);
		source = (unsigned char*)src + (n - 1);
		while (n--)
			*destination-- = *source--;
	}
	return (dest);
}
