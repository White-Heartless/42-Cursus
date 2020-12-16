#include "libft.h"

/*
*Takes string str and finds the first occurrence of char c
*typecasted to unsigned char.
*returns a pointer to the character found or Null if it is not present in str
*/

char	*ft_strchr(const char *str, int c)
{
	char *s;

	s = (char *)str;
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (s);
		s++;
	}
	return (NULL);
}
