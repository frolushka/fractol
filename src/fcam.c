/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcam.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:23:07 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/02 22:56:58 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fcam	*fcam_init(const t_fmode mode, const float mspeed, const float sspeed)
{
	t_fcam	*res;

	if (!(res = (t_fcam *)malloc(sizeof(t_fcam))))
		return (NULL);
	res->coord[0] = 0;
	res->coord[1] = 0;
	res->coord[2] = 1;
	res->mode = mode;
	res->mspeed = mspeed;
	res->sspeed = sspeed;
	return (res);
}

t_fcam	*fcam_delete(t_fcam **fcam)
{
	ft_memdel((void **)fcam);
	return (*fcam);
}

void	fcam_move(t_fcam *fcam, const float dx, const float dy)
{
	fcam->coord[0] += dx * fcam->mspeed / fcam->coord[2];
	fcam->coord[1] += dy * fcam->mspeed / fcam->coord[2];
}

void	fcam_scale(t_fcam *fcam, const float s)
{
	float sspeed;

	sspeed = s > 0 ? fcam->sspeed : 1 / fcam->sspeed;
	fcam->coord[2] *= sspeed;
}
