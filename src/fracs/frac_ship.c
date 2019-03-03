/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 01:53:34 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/03 03:08:17 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void inline	frac_ship(float *p)
{
	float	t1;
	float	t2;

	t1 = p[0] * p[0] - p[1] * p[1] + p[2];
	t2 = ft_fabs(2 * p[0] * p[1]) + p[3];
	p[0] = t1;
	p[1] = t2;
}

int					frac_ship_get_color(t_frac *f, float *p)
{
	short	it;
    float   st;

	p[0] = 0;
	p[1] = 0;
	it = -1;
	while (++it < f->its)
	{
		frac_ship(p);
		if (p[0] * p[0] + p[1] * p[1] > f->r * f->r)
			break;
	}
	st = it / (float)f->its;
	return color_lerp(COLOR_BLUE, COLOR_RED, st);
}