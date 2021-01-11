#include "../libft.h"

/*
*allocates a fresh substring starting from the start index of s and is of size len
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!(s))
		return (NULL);
	substr = ft_strnew(len);
	if (substr == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (s[i] && i < len)
		{
			substr[i] = s[start + i];
			i++;
		}
	}
	substr[i] = 0;
	return (substr);
}
