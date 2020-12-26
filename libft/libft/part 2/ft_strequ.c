#include "../libft.h"

/*
*compares s1 and s2
*returns 1 if the strings are identical and 0 otherwise
*/

int	ft_strequ(char const *s1, char const *s2)
{
	size_t i;
	int flag;

	i = 0;
	flag = 1;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			flag = 0;
		i++;
	}
	if (s1[i] != s2[i])
			flag = 0;
	return (flag);
}

