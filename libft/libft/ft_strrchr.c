#include "libft.h"

/*
*Takes string str and finds the last occurrence of char c
*typecasted to unsigned char.
*returns a pointer to the character found or Null if it is not present in str
*/

char	*ft_strrchr(const char *str, int c)
{
	char *start;
	char *s;

	start = (char *)str;
	s = (char *)str + ft_strlen(str);
	while (s > start)
	{
		if (*s == (unsigned char)c)
			return (s);
		s--;
	}
	return (NULL);
}

