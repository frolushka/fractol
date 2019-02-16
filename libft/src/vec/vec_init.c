/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:42:43 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 19:19:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vec_init(const size_t size, const size_t block_size)
{
	t_vector	*res;

	if (size == 0 || block_size == 0)
		return (NULL);
	if (!(res->data = (char *)malloc(size * block_size)))
		return (NULL);
	res->size = size;
	res->block_size = block_size;
	vec_clear(res);
	return (res);
}
