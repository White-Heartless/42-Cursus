#include "../libft.h"

/*
*Takes string haystack and finds the first occurrence of string needle
*searching no more than n characters
*returns a pointer to the first character of the found string in haystack,
*or a Null pointer if the sequence is not present in haystack.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;

	if (len == 0)
		return (NULL);
	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && len--)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && (j <= len))
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
