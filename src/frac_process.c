/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 04:32:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:16:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	frac_print_info(t_frac *f)
{
	char	text[1024];

	sprintf(text, "USEFUL BUTTONS:");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 20, COLOR_GREEN, text);
	sprintf(text, "> MOVE - W A S D");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 40, COLOR_GREEN, text);
	sprintf(text, "> SCALE - Q E");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 55, COLOR_GREEN, text);
	sprintf(text, "> RESET POS - R");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 70, COLOR_GREEN, text);
	sprintf(text, "> MODE - ARROWS L & R");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 85, COLOR_GREEN, text);
}

static int	frac_draw_get_color(t_frac *f, long double *p)
{
	if (f->fcam->mode == MODE_MANDELBROT)
		return (frac_mandelbrot_get_color(f, p));
	if (f->fcam->mode == MODE_JULIA)
		return (frac_julia_get_color(f, p));
	if (f->fcam->mode == MODE_SHIP)
		return (frac_ship_get_color(f, p));
	if (f->fcam->mode == MODE_RADIO)
		return (frac_radio_get_color(f, p));
	return (0);
}

static void	*frac_draw(void *v)
{
	long double		p[6];
	short		xy[2];
	t_tfrac		*f;

	f = (t_tfrac *)v;
	p[4] = 3.0f / f->f->fcam->coord[2] / f->f->mlx->width;
	p[5] = 3.0f / f->f->fcam->coord[2] / f->f->mlx->height;
	xy[1] = (short)f->i;
	p[3] = -1.5f / f->f->fcam->coord[2] + f->f->fcam->coord[1] + xy[1] * p[5];
	while (xy[1] < f->f->mlx->height)
	{
		xy[0] = -1;
		p[2] = -2.0f / f->f->fcam->coord[2] + f->f->fcam->coord[0];
		while (++xy[0] < f->f->mlx->width)
		{
			image_set_pixel(f->f->mlx->image, xy[0] - f->f->mlx->width / 2,
				xy[1] - f->f->mlx->height / 2, frac_draw_get_color(f->f, p));
			p[2] += p[4];
		}
		p[3] += p[5] * f->f->tc;
		xy[1] += f->f->tc;
	}
	return (NULL);
}

static void	pointer_draw(t_frac *f)
{
	image_set_pixel(f->mlx->image, 0, 0, COLOR_RED);
	image_set_pixel(f->mlx->image, 1, 0, COLOR_RED);
	image_set_pixel(f->mlx->image, 0, 1, COLOR_RED);
	image_set_pixel(f->mlx->image, 1, 1, COLOR_RED);
	image_set_pixel(f->mlx->image, -1, 0, COLOR_RED);
	image_set_pixel(f->mlx->image, 0, -1, COLOR_RED);
	image_set_pixel(f->mlx->image, -1, -1, COLOR_RED);
	image_set_pixel(f->mlx->image, -1, 1, COLOR_RED);
	image_set_pixel(f->mlx->image, 1, -1, COLOR_RED);
}

void		frac_process(t_frac *f)
{
	t_tfrac		tfs[f->tc];
	pthread_t	ts[f->tc];
	int			i;

	image_clear(f->mlx->image);
	i = -1;
	while (++i < f->tc)
	{
		tfs[i].i = i;
		tfs[i].f = f;
		pthread_create(&ts[i], NULL, frac_draw, (void *)&tfs[i]);
	}
	i = -1;
	while (++i < f->tc)
		pthread_join(ts[i], NULL);
	pointer_draw(f);
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->mlx->image->image, 0, 0);
	frac_print_info(f);
}
