/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnumiter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbozhko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 15:09:35 by rbozhko           #+#    #+#             */
/*   Updated: 2016/12/18 16:16:49 by rbozhko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnumiter(t_list *elem, size_t len)
{
	t_list	*temp;

	if (elem && len)
	{
		len -= 1;
		temp = elem;
		while (--len && temp)
		{
			temp = temp->next;
		}
		return (temp);
	}
	return (NULL);
}
