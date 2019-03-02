/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:38:25 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/02 19:49:10 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*fmlx_delete(t_mlx **mlx)
{
	if (!mlx || !*mlx)
		return (NULL);
	if (((*mlx)->mlx))
		ft_memdel((void **)&((*mlx)->mlx));
	if (((*mlx)->win))
		ft_memdel((void **)&((*mlx)->win));
	if (((*mlx)->image))
		ft_memdel((void **)&((*mlx)->image));
	ft_memdel((void **)mlx);
	return (*mlx);
}

t_mlx	*fmlx_init(const int width, const int height, char *header)
{
	t_mlx	*res;

	if (!(res = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	res->width = width;
	res->height = height;
	res->mlx = NULL;
	res->win = NULL;
	res->image = NULL;
	if (!(res->mlx = mlx_init()) ||
		!(res->win = mlx_new_window(res->mlx, width, height, header)) ||
		!(res->image = image_init(res, width, height)))
		return (fmlx_delete(&res));
	return (res);
}
