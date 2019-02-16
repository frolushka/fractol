/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:11:31 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 19:20:46 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*vec_get(t_vector *vec, const size_t i1)
{
	if (!vec || i1 >= vec->size)
		return (NULL);
	return (vec->data[vec->block_size * i1]);
}
