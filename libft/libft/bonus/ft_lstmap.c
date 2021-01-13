#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*toret;
	t_list	*tmp;

	toret = NULL;
	while (lst)
	{
		if (!(tmp = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&toret, del);
			return (NULL);
		}
		ft_lstadd_back(&toret, tmp);
		lst = lst->next;
	}
	return (toret);
}
