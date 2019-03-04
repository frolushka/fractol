/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:55:01 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:56:41 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int hook_mouse(const int x, const int y, t_frac *f)
{
	clock_t	ct;

	ct = clock();
	if (FPS * (ct - f->lt) / CLOCKS_PER_SEC < 1)
		return (0);
	f->lt = ct;
	if (f->lmx == -1 && f->lmy == -1)
	{
		f->lmx = x;
		f->lmy = y;
		return (0);
	}
	if (f->fcam->mode == MODE_JULIA)
	{
		f->fcam->coord[0] += (x - f->lmx) * 3.0f / f->fcam->coord[2] / f->mlx->width;
		f->fcam->coord[1] += (y - f->lmy) * 3.0f / f->fcam->coord[2] / f->mlx->height;
	}
	f->lmx = x;
	f->lmy = y;
	frac_process(f);
    return (0);
}

int	hook_mouse_key(const int key, int x, int y, t_frac *f)
{
	clock_t	ct;

	ct = clock();
	if (FPS * (ct - f->lt) / CLOCKS_PER_SEC < 1)
		return (0);
	f->lt = ct;

	if (key == MOUSE_KEY_LEFT)
	{
		f->fcam->coord[0] += (x - f->lmx) * 3.0f / f->fcam->coord[2] / f->mlx->width;
		f->fcam->coord[1] += (y - f->lmy) * 3.0f / f->fcam->coord[2] / f->mlx->height;
	}
	else if (key == SCROLL_UP)
		f->fcam->coord[2] *= 1.1;
	else if (key == SCROLL_DOWN)
		f->fcam->coord[2] = (f->fcam->coord[2] / 1.1 < 1 ? 1 : f->fcam->coord[2] / 1.1);
	frac_process(f);
	f->lmx = x;
	f->lmy = y;
	return (0);
}