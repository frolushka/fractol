/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 19:59:07 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:40:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void inline	frac_mandelbrot(long double *p)
{
	long double	t1;
	long double	t2;

	t1 = p[0] * p[0] - p[1] * p[1] + p[2];
	t2 = 2 * p[0] * p[1] + p[3];
	p[0] = t1;
	p[1] = t2;
}

int					frac_mandelbrot_get_color(t_frac *f, long double *p)
{
	short	it;
	long double	r;
	long double	t;
	long double	pc;

	r = sqrt((p[2] - 0.25f) * (p[2] - 0.25f) + p[3] * p[3]);
	t = atan2(p[3], p[2] - 0.25f);
	pc = 0.5f - 0.5f * cos(t);
	if (r <= pc)
		return (COLOR_WHITE);
	p[0] = 0;
	p[1] = 0;
	it = -1;
	while (++it < f->its)
	{
		frac_mandelbrot(p);
		if (p[0] * p[0] + p[1] * p[1] > f->r * f->r)
			break;
	}
	return (get_color(it, f));
}
