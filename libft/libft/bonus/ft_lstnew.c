#include "../libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*add;

	if (!(add = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	add -> next = NULL;
	add -> content = content;
	return (add);
}
