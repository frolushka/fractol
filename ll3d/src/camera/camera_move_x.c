/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 05:44:00 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:01:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void	camera_move_x_1(long double val[4][4], const long double l)
{
	val[3][0] += val[0][0] * l;
	val[3][1] += val[0][1] * l;
	val[3][2] += val[0][2] * l;
}

void		camera_move_x(t_cam *cam, const long double l)
{
	camera_move_x_1(cam->cam->val, l * cam->speed);
}
