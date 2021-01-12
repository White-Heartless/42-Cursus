#include "../libft.h"
#include <stdio.h>
/*
**Takes an integer as input and puts it into
**a freshly allocated array.
*/

char	*ft_itoa(int n)
{
	long long	ln;
	char	*arr;
	long long	i;
	int		numlen;
	int		divisor;

	n < 0 ? (ln = (long long)n * -1) : (ln = (long long)n);
	n < 0 ? (numlen = 2) : (numlen = 1);
	i = 1;
	while (ln >= (i *= 10))
		numlen++;
	if(!(arr = (char *)malloc((sizeof(char) * numlen) + 1)))
		return (NULL);
	n < 0 ? (arr[0] = '-') : (n = n);
	i = numlen - 1;
	divisor = 10;
	while (n < 0 ? (i > 0) : (i >= 0))
	{
		arr[i] = '0' + (ln % divisor);
		i--;
		ln /= 10;
	}
	arr[numlen] = 0;
	return (arr);
}
