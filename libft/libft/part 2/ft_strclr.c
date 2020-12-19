#include "../libft.h"

// sets every character of the passed string to 0

void	ft_strclr(char *s)
{
	ft_memset((void *)s,0,ft_strlen(s));
}
