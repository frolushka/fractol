/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:03:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 19:13:10 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	vec_clear(t_vector *vec)
{
	if (!vec)
		return ;
	ft_bzero(vec->data, vec->size * vec->block_size);
	vec->last = 0;
}
