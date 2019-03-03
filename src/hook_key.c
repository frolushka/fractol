/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:44:24 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/03 02:44:36 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	inline	hook_esc(t_frac *frac)
{
	frac_delete(&frac);
	exit(0);
}

static void inline	hook_key_change(const int key, t_frac *frac)
{
	if (key == KEY_E)
		fcam_scale(frac->fcam, 1);
	else if (key == KEY_Q)
		fcam_scale(frac->fcam, -1);
	else if (key == KEY_ARROWL)
		frac->fcam->mode = (frac->fcam->mode + MODE_COUNT - 1) % MODE_COUNT;
	else if (key == KEY_ARROWR)
		frac->fcam->mode = (frac->fcam->mode + 1) % MODE_COUNT;
}

static void inline	hook_key_move(const int key, t_frac *frac)
{
	if (key == KEY_W)
		fcam_move(frac->fcam, 0, -1);
	else if (key == KEY_S)
		fcam_move(frac->fcam, 0, 1);
	else if (key == KEY_D)
		fcam_move(frac->fcam, 1, 0);
	else if (key == KEY_A)
		fcam_move(frac->fcam, -1, 0);
	else if (key == KEY_R)
	{
		frac->fcam->coord[0] = 0;
		frac->fcam->coord[1] = 1;
	}

}

int					hook_mouse_key(const int key, int x, int y, t_frac *f)
{
	if (key == MOUSE_KEY_LEFT)
	{
		if (f->fcam->mode != MODE_JULIA)
		{
			f->fcam->coord[0] += (x - f->mlx->width / 2) * 3.0f / f->fcam->coord[2] / f->mlx->width;
			f->fcam->coord[1] += (y - f->mlx->height / 2) * 3.0f / f->fcam->coord[2] / f->mlx->height;
			fcam_scale(f->fcam, 1);
		}
		else
		{
			f->fcam->coord[0] = (x - f->mlx->width / 2) * 3.0f / f->fcam->coord[2] / f->mlx->width;
			f->fcam->coord[1] = (y - f->mlx->height / 2) * 3.0f / f->fcam->coord[2] / f->mlx->height;
		}
	}
	else if (key == MOUSE_KEY_RIGHT && f->fcam->mode != MODE_JULIA)
		fcam_scale(f->fcam, -1);
	frac_process(f);
	return (0);
}

int					hook_key(const int key, t_frac *frac)
{
	hook_key_move(key, frac);
	hook_key_change(key, frac);
	if (key == KEY_ESC)
		hook_esc(frac);
	frac_process(frac);
	return (0);
}
