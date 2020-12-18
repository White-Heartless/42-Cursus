#include "../libft.h"

/*
*compares s1 and s2, up to n characters
*returns a value lesser, equal , or greater than 0 if
*s1 is lesser, equal, or greater than s2 respectively.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

