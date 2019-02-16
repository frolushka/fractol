/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:13:26 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 19:19:28 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec_set(t_vector *vec, const char *val, const size_t i1)
{
	size_t	i;
	size_t	b;

	if (!vec || i1 >= vec->size)
		return ;
	i = -1;
	b = vec->block_size * i1;
	while (++i < vec->block_size)
		vec->data[b + i] = val[i];
}
