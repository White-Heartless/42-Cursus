#include "../libft.h"

/*
*Takes string haystack and finds the first occurrence of string needle
*returns a pointer to the first character of the found string in haystack,
*or a Null pointer if the sequence is not present in haystack.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (needle[j + 1] == 0)
			{
				return ((char *)(haystack + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}

