/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_lerp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 19:42:55 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:01:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

int	color_lerp(const int c1, const int c2, const long double step)
{
	int	r;
	int	g;
	int	b;

	r = (((c2 & 0xFF0000) >> 16) - ((c1 & 0xFF0000) >> 16)) * step +
		((c1 & 0xFF0000) >> 16);
	g = (((c2 & 0xFF00) >> 8) - ((c1 & 0xFF00) >> 8)) * step +
		((c1 & 0xFF00) >> 8);
	b = ((c2 & 0xFF) - (c1 & 0xFF)) * step +
		(c1 & 0xFF);
	return (r << 16 | g << 8 | b);
}
