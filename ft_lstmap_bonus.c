/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:14:10 by tspoof            #+#    #+#             */
/*   Updated: 2022/11/07 16:32:16 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);

	while (lst)
	{
		if (f)
			ft_lstadd_front(&new_lst, ft_lstnew(f(lst->content)));
		if (del)
			del(lst);
		lst = lst->next;
	}
	return (new_lst);
}
