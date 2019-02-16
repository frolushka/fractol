/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:56:23 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 22:51:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractol	*fractol_init(const size_t size_x, const size_t size_y)
{
	t_fractol	*res;

	if ((size_x <= 0 || size_y <= 0) ||
		!(res = (t_fractol *)malloc(sizeof(t_fractol))))
		return (NULL);
	if (!(res->map = (short *)malloc(size_x * size_y * sizeof(short))))
	{
		free(res);
		return (NULL);
	}
	ft_bzero(res->map, size_x * size_y * sizeof(short));
	res->max_iters = DEFAULT_MAX_ITERS;
	res->size_x = size_x;
	res->size_y = size_y;
	res->center_x = size_x / 2;
	res->center_y = size_y / 2;
	res->mlx = NULL;
	return (res);
}
