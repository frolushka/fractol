/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_per_calc_piv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:36:29 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/14 20:36:32 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

static void inline	camera_pcv_val(t_vec3 *res, const float val[4][4],
	const float focus)
{
	res->x = val[3][0] - val[2][0] * focus;
	res->y = val[3][1] - val[2][1] * focus;
	res->z = val[3][2] - val[2][2] * focus;
}

void				camera_per_calc_piv(t_cam *cam)
{
	t_vec3	*res;

	res = vec3_init();
	camera_pcv_val(res, cam->cam->val, cam->focus);
	if (cam->piv)
		free(cam->piv);
	cam->piv = res;
}
