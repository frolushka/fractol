/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:21:08 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/02 23:18:55 by sbednar          ###   ########.fr       */
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

	// printf("\ncompute point:\n%.3f %.3f %.3f %.3f\n", p[0], p[1], p[2], p[3]);
	p[0] = p[2];
	p[1] = p[3];
	p[2] = f->fcam->coord[0];
	p[3] = f->fcam->coord[1];
	// printf("new values %.3f %.3f %.3f %.3f\n", p[0], p[1], p[2], p[3]);
	it = -1;
	// printf("start iters\n");
	while (++it < f->its)
	{
		frac_julia(p);
		// printf("after %d iter %.3f %.3f %.3f %.3f\n", it, p[0], p[1], p[2], p[3]);
		if (p[0] * p[0] + p[1] * p[1] > f->r * f->r)
			break;
	}
	return ((it << 16) | (it << 8) | it);
}
