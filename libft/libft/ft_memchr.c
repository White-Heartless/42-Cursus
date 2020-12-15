#include "libft.h"

// Finds the first occurrence of char c, stopping after n bytes
// str ==> Starting address of memory to be searched
// c   ==> Value to be found
// n   ==> Number of bytes after which to stop
// Return value: pointer to the first occurrence of the char
// or NULL if the char is not found

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *address;

	address = (unsigned char*)str;
	while (n-- > 0)
	{
		if (*address == (unsigned char)c)
			return (address);
		address++;
	}
	return (NULL);
}

