#include "../libft.h"

/*
*Applies the function f to each character of the string passed
*as argument by giving it's index as argument.
*A new string is created in which the results of the operations are stored
*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	if(s && f)
	{
		size_t i;

		i= 0;
		char *newstr = (char *)malloc(sizeof(char) * ft_strlen(s));
		if (newstr)
		{
			while (s[i])
			{
				newstr[i] = f((unsigned int)i,s[i]);
				i++;
			}
			newstr[i] = 0;
			return (newstr);
		}
	}
	return (NULL);
}

