/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:53:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 22:49:37 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_mlx		*mlx;
	t_fractol	*frac;

	if (!(mlx = mlx_init_ll3d(SCREEN_X, SCREEN_Y, SCREEN_NAME)))
	{
		perror("Couldn't init t_mlx in function main.");
		exit(0);
	}
	if (!(frac = fractol_init(mlx->width, mlx->height)))
	{
		perror("Couldn't init t_fractol in function main.");
		mlx_free_ll3d(&mlx);
		exit(1);
	}
	frac->mlx = mlx;
	for (size_t it = 0; it < frac->max_iters; ++it)
	{
		for (size_t y = 0; y < frac->size_y; ++y)
		{
			for (size_t x = 0; x < frac->size_x; ++x)
			{
				if (it == 0)
				{
					int r = x * x - y * y;
					int i = 2 * x * y;
					if (!(r < 0 || r >= (int)frac->size_x / 2 || i < 0 || i >= (int)frac->size_y / 2))
						frac->map[i * frac->size_x + r] = 1;
				}
				else if (frac->map[y * frac->size_x + x] != 0)
				{
					int r = x * x - y * y;
					int i = 2 * x * y;
					if (!(r < 0 || r >= (int)frac->size_x / 2 || i < 0 || i >= (int)frac->size_y / 2))
						frac->map[i * frac->size_x + r] = it;
				}
			}
		}
	}
	for (size_t y = 0; y < frac->size_y; ++y)
	{
		for (size_t x = 0; x < frac->size_x; ++x)
		{
			image_set_pixel(mlx->image, x, y, frac->map[y * frac->size_x + x] == 0 ? 0 : 0xFFFFFF);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->image->image, 0, 0);
	mlx_hook(mlx->win, 2, 0, hook_key, frac);
	mlx_loop(mlx->mlx);
	return (0);
}
