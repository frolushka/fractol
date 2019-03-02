/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 04:32:14 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/02 23:46:25 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	frac_print_info(t_frac *f)
{
	char	text[1024];

	sprintf(text, "CAMERA POSITION:");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 20, COLOR_WHITE, text);
	sprintf(text, "%.3f %.3f", f->fcam->coord[0], f->fcam->coord[1]);
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 40, COLOR_WHITE, text);
	sprintf(text, "MAXIMUM ITERATIONS:");
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 60, COLOR_WHITE, text);
	sprintf(text, "%d", f->its);
	mlx_string_put(f->mlx->mlx, f->mlx->win, 20, 80, COLOR_WHITE, text);
}

static int	frac_draw_get_color(t_frac *f, float *p)
{
	if (f->fcam->mode == MODE_MANDELBROT)
		return frac_mandelbrot_get_color(f, p);
	if (f->fcam->mode == MODE_JULIA)
		return frac_julia_get_color(f, p);
	return (0);
}

static void	*frac_draw(void *v)
{
	// cp[0] cp[1] p[0] p[1] step[0] step[1]
	// p[0]  p[1]  p[2] p[3] p[4]    p[5]
	float		p[6];
	short		xy[2];
	t_frac		*f;
	static int	i = -1;

	f = (t_frac *)v;
	p[4] = 3.0f / f->fcam->coord[2] / f->mlx->width;
	p[5] = 3.0f / f->fcam->coord[2] / f->mlx->height;
	xy[1] = ++i;
	i = (i == f->tc ? 0 : i);
	p[3] = -1.5f / f->fcam->coord[2] + f->fcam->coord[1] + xy[1] * p[5];
	while (xy[1] < f->mlx->height)
	{
		xy[0] = -1;
		p[2] = -2.0f / f->fcam->coord[2] + f->fcam->coord[0];
		while (++xy[0] < f->mlx->width)
		{
			image_set_pixel(f->mlx->image, xy[0] - f->mlx->width / 2,
				xy[1] - f->mlx->height / 2, frac_draw_get_color(f, p));
			p[2] += p[4];
		}
		p[3] += p[5] * f->tc;
		xy[1] += f->tc;
	}
	return (NULL);
}

void		frac_process(t_frac *f)
{
	pthread_t	threads[f->tc];
	int			i;

	image_clear(f->mlx->image);
	i = -1;
	while (++i < f->tc)
		pthread_create(&threads[i], NULL, frac_draw, (void *)f);
	i = -1;
	while (++i < f->tc)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(f->mlx->mlx, f->mlx->win, f->mlx->image->image, 0, 0);
	frac_print_info(f);
}
