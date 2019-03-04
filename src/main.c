/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:53:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:42:37 by sbednar          ###   ########.fr       */
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
	return (-1);
}

static void		fill_colors(t_frac *f)
{
	f->colors[0][0] = 0;
	f->colors[1][0] = 0x000000;
	f->colors[0][1] = 32;
	f->colors[1][1] = 0xFF0000;
	f->colors[0][2] = 64;
	f->colors[1][2] = 0x00FF00;
	f->colors[0][3] = 96;
	f->colors[1][3] = 0x0000FF;
	f->colors[0][4] = 128;
	f->colors[1][4] = 0xFF00FF;
	f->colors[0][5] = 160;
	f->colors[1][5] = 0x00FFFF;
	f->colors[0][6] = 192;
	f->colors[1][6] = 0xFFFF00;
	f->colors[0][7] = 255;
	f->colors[1][7] = 0xFFFFFF;
}

int	main(int ac, char **av)
{
	t_frac	*f;
	char m;

	if (ac != 2 || (m = get_mode_from_str(av[1])) < 0)
	{
		ft_putendl("usage: ./fractol [MADNELBROT|JULIA|SHIP|RADIO]");
		exit(0);
	}
	f = default_init(m);
	fill_colors(f);
	frac_process(f);
	mlx_hook(f->mlx->win, 6, 0, hook_mouse, f);
	mlx_hook(f->mlx->win, 4, 0, hook_mouse_key, f);
	mlx_hook(f->mlx->win, 2, 0, hook_key, f);
	mlx_loop(f->mlx->mlx);
	return (0);
}
