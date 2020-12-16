#include "libft.h"

/*
*Takes a string as input and returns a copy of the string,
*allocated with malloc.
*/
char	*ft_strdup(const char *src)
{
	char	*duplicate;
	int		i;

	i = -1;
	if ((duplicate = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	while (src[++i])
		duplicate[i] = src[i];
	duplicate[i] = 0;
	return (duplicate);
}

