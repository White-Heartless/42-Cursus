#include "../libft.h"

/*
*compares s1 and s2 up to n chars
*returns 1 if the strings are identical and 0 otherwise
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] != s2[i] && i < n)
			return (0);
	return (1);
}
