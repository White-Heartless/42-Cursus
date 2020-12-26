#include "../libft.h"

/*
*Applies the function f to each character of the string passed
*as argument. Each character is passed as argument to f to be
*modified if necessary
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	index = 0;
	if(s && f)
	{
		while (s[index])
		{
			f(index, &s[index]);
			index++;
		}
	}
}



