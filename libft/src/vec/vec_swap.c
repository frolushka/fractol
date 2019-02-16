/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:06:15 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 19:19:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec_swap(t_vector *vec, const size_t i1, const size_t i2)
{
	size_t	i;
	size_t	b1;
	size_t	b2;
	char	temp;

	if (!vec || i1 >= vec->size || i2 > vec->size)
		return ;
	i = -1;
	b1 = vec->block_size * i1;
	b2 = vec->block_size * i2;
	while (++i < vec->block_size)
	{
		temp = vec->data[b1 + i];
		vec->data[b1 + i] = vec->data[b2 + i];
		vec->data[b2 + i] = temp;
	}
}
