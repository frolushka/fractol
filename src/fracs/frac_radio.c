/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_radio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 02:16:37 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/03 02:19:16 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void inline	frac_radio(float *p)
{
	float	t1;
	float	t2;

	t1 = p[0] * p[0] * p[0] - 3 * p[0] * p[1] * p[1] + p[2];
	t2 = 3 * p[0] * p[0] * p[1] - p[1] * p[1] * p[1] + p[3];
	p[0] = t1;
	p[1] = t2;
}

int					frac_radio_get_color(t_frac *f, float *p)
{
	short	it;
	float	p1[4];

	p1[0] = p[2];
	p1[1] = p[3];
	p1[2] = 0.5f;
	p1[3] = 0;
	it = -1;
	while (++it < f->its)
	{
		frac_radio(p1);
		if (p1[0] * p1[0] + p1[1] * p1[1] > f->r * f->r)
			break;
	}
	it = (int)(it / (float)f->its * 255);
	return ((it << 16) | (it << 8) | it);
}