/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 01:53:34 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:41:04 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void inline	frac_ship(long double *p)
{
	long double	t1;
	long double	t2;

	t1 = p[0] * p[0] - p[1] * p[1] + p[2];
	t2 = ft_fabs(2 * p[0] * p[1]) + p[3];
	p[0] = t1;
	p[1] = t2;
}

int					frac_ship_get_color(t_frac *f, long double *p)
{
	short	it;

	p[0] = 0;
	p[1] = 0;
	it = -1;
	while (++it < f->its)
	{
		frac_ship(p);
		if (p[0] * p[0] + p[1] * p[1] > f->r * f->r)
			break;
	}
	return (get_color(it, f));
}