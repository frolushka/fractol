/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:21:08 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/02 23:44:45 by sbednar          ###   ########.fr       */
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

	p[0] = p[2];
	p[1] = p[3];
	p[2] = f->fcam->coord[0];
	p[3] = f->fcam->coord[1];
	it = -1;
	while (++it < f->its)
	{
		frac_julia(p);
		if (p[0] * p[0] + p[1] * p[1] > f->r * f->r)
			break;
	}
	return ((it << 16) | (it << 8) | it);
}
