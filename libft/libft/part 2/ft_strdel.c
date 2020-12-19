#include "../libft.h"

/*
*frees the passed string and sets its pointer to NULL
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
