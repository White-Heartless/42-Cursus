#include "../libft.h"

/*
*frees the passed memory area and sets its pointer to NULL
*/

void	ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

