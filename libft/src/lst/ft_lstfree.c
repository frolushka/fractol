/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 17:04:51 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 17:07:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **root)
{
	t_list	*cur;
	t_list	*tmp;

	if (!root || !*root)
		return ;
	cur = *root;
	while (cur)
	{
		tmp = cur->next;
		if (cur->content)
			free(cur->content);
		free(cur);
		cur = tmp;
	}
	root = NULL;
}
