#include "../libft.h"

static int wcount(char *s, char c)
{
	int prev;
	int i;
	int count;

	prev = -1;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && i - prev == 1)
			count++;
		if (s[i] == c)
			prev = i;
		i++;
	}
	return (count);
}

static void fill(char *dst, int j, int i, char *src)
{
	int len;
	int counter;

	len = j - i;
	counter = 0;
	while (counter < len)
	{
		dst[counter] = src[i];
		i++;
		counter++;
	}
	dst[counter] = 0;
}

char **ft_split(char const *s, char c)
{
	char **arr;
	int i;
	int j;
	int x;

	if(!(arr = (char **)malloc(sizeof(char *) * (wcount((char *)s,c) + 1))))
		return (NULL);
	arr[wcount((char *)s,c)] = NULL;
	i = 0;
	x = 0;
	while (i < (int)ft_strlen(s))
	{
		if(s[i] != c)                    // i, arr, s, c
		{
			j = i + 1;
			while (s[j] && s[j] != c)
				j++;
			if(!(arr[x] = (char *)malloc(sizeof(char) * (j - i + 1))))
				return (NULL);
			fill(arr[x++], j , i, (char *)s);
			i = j + 1;
			continue;
		}
		i++;
	}
	return (arr);
}
