
#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	if (lst && *lst)
	{
		list = *lst;
		*lst = NULL;
		while (list)
		{
			tmp = list->next;
			del(list->content);
			free(list);
			list = tmp;
		}
	}
}
