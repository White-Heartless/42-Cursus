#include "libft.h"

/*
*compares s1 and s2
*returns a value lesser, equal , or greater than 0 if
*s1 is lesser, equal, or greater than s2 respectively.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
