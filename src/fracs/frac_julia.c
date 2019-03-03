/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:21:08 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/03 02:08:05 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void inline	frac_julia(float *p)
{
	float	t1;
	float	t2;

	t1 = p[0] * p[0] - p[1] * p[1] + p[2];
	t2 = 2 * p[0] * p[1] + p[3];
	p[0] = t1;
	p[1] = t2;
}

int					frac_julia_get_color(t_frac *f, float *p)
{
	short	it;
	float	p1[4];

	p1[0] = p[2];
	p1[1] = p[3];
	p1[2] = f->fcam->coord[0];
	p1[3] = f->fcam->coord[1];
	it = -1;
	while (++it < f->its)
	{
		frac_julia(p1);
		if (p1[0] * p1[0] + p1[1] * p1[1] > f->r * f->r)
			break;
	}
	it = (int)(it / (float)f->its * 255);
	return ((it << 16) | (it << 8) | it);
}
