#include "../libft.h"

/*
*Takes string source and concatenates up to n chars from it
*after the end of destination, replacing the '\0' in destination,
*and adding the '\0' from the source at the end.
*This function guarantees that the '\0' will always be placed
*dest HAS to be big enough to contain n chars, or you will segfault
*/

size_t	ft_strlcat(char* dest, const char* src, size_t n)
{
	char			*d;
	char			*s;
	unsigned int	i;

	d = dest;
	s = (char *)src;
	i = n;
	while (i-- != 0 && *d)
		d++;
	if (i == 0)
		return (ft_strlen(dest) + ft_strlen(src));
	while (*s)
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = 0;
	return (ft_strlen(dest) + ft_strlen(src));
}
