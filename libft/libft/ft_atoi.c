#include "libft.h"

/*
*extracts and integer from a string
*/

int	ft_atoi(const char *s1)
{
	int				sign;
	unsigned int	result;

	sign = 1;
	result = 0;
	while (*s1 == ' ' || (*s1 >= 9 && *s1 <= 13))
		s1++;
	if (*s1 == '+' || *s1 == '-')
	{
		if (*s1 == '-')
			sign = -1;
		s1++;
	}
	while (*s1 >= '0' && *s1 <= '9')
	{
		result = result * 10 + (*s1 - '0');
		s1++;
	}

	return ((int)result * sign);
}

