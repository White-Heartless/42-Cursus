#include "../libft.h"

int ft_lstsize(t_list *lst)
{
	int counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst -> next;
	}
	return (counter);
}
