/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oclude_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 00:31:40 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:01:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	oclude_z(t_vec2 *d1, t_vec2 *d2, long double z1, long double z2)
{
	if (z1 > 0 && z2 > 0)
		return ;
	if (d2->y > d1->y)
		d2->y = d2->y + (int)((long double)
			((d2->y - d1->y) * (z2))
			/ (long double)(z1 - z2));
	else
		d2->y = d2->y + (int)((long double)
			((d2->y - d1->y) * (z2))
			/ (long double)(z1 - z2));
	if (d2->x > d1->x)
		d2->x = d2->x + (int)((long double)
			((d2->x - d1->x) * z2)
			/ (long double)(z1 - z2));
	else
		d2->x = d2->x + (int)((long double)
			((d2->x - d1->x) * z2)
			/ (long double)(z1 - z2));
}
