/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots_color_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:43:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 20:38:09 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

void	dots_color_update(t_dots *dots)
{
	int	i;
	int	len;

	i = -1;
	len = dots->xc * dots->yc;
	while (++i < len)
		if ((int)(dots->wb[i]->w) >> 24 != 0)
			dots->wb[i]->w = color_get_default(dots->wb[i]->y, dots->cm);
}
