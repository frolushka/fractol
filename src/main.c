/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:53:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/03 02:21:05 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static t_frac	*default_init(char mode)
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

static char		get_mode_from_str(const char *str)
{
	if (!ft_strcmp(str, "MANDELBROT"))
		return (MODE_MANDELBROT);
	if (!ft_strcmp(str, "JULIA"))
		return (MODE_JULIA);
	if (!ft_strcmp(str, "SHIP"))
		return (MODE_SHIP);
	if (!ft_strcmp(str, "RADIO"))
		return (MODE_RADIO);
	return (MODE_MANDELBROT);
}

int	main(int ac, char **av)
{
	t_frac	*f;
	char m;

	m = (ac == 2 ? get_mode_from_str(av[1]) : MODE_MANDELBROT);
	f = default_init(m);
	frac_process(f);
	mlx_hook(f->mlx->win, 4, 0, hook_mouse_key, f);
	mlx_hook(f->mlx->win, 2, 0, hook_key, f);
	mlx_loop(f->mlx->mlx);
	return (0);
}
