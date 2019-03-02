/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:53:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/02 22:31:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static t_frac	*default_init(t_fmode mode)
{
	t_frac	*frac;
	t_mlx	*mlx;
	t_fcam	*fcam;

	if (!(frac = frac_init(DEFAULT_MAX_RADIUS, DEFAULT_MAX_ITERS)))
	{
		perror("Couldn't init t_frac in default_init.");
		exit(1);
	}
	if (!(mlx = fmlx_init(SCREEN_X, SCREEN_Y, SCREEN_NAME)))
	{
		frac_delete(&frac);
		perror("Couldn't init t_fcam in default_init.");
		exit(1);
	}
	if (!(fcam = fcam_init(mode, DEFAULT_MSPEED, DEFAULT_SSPEED)))
	{
		frac_delete(&frac);
		fmlx_delete(&mlx);
		perror("Couldn't init t_mlx in default_init.");
		exit(1);
	}
	frac->fcam = fcam;
	frac->mlx = mlx;
	return (frac);
}

static t_fmode	get_mode_from_str(const char *str)
{
	if (!ft_strcmp(str, "MANDELBROT"))
		return ((t_fmode)0);
	if (!ft_strcmp(str, "JULIA"))
		return ((t_fmode)1);
	if (!ft_strcmp(str, "SHIP"))
		return ((t_fmode)2);
	return ((t_fmode)0);
}

int	main(int ac, char **av)
{
	t_frac	*f;
	t_fmode m;

	m = (ac == 2 ? get_mode_from_str(av[1]) : (t_fmode)0);
	f = default_init(m);
	frac_process(f);
	mlx_hook(f->mlx->win, 2, 0, hook_key, f);
	mlx_loop(f->mlx->mlx);
	return (0);
}
