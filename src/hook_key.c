/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:44:24 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/02 22:43:38 by sbednar          ###   ########.fr       */
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
	else if (key == KEY_R)
		frac->its++;
	else if (key == KEY_F)
		frac->its--;
}

static void inline	hook_key_move(const int key, t_frac *frac)
{
	if (key == KEY_W)
		fcam_move(frac->fcam, 0, -1);
	if (key == KEY_S)
		fcam_move(frac->fcam, 0, 1);
	if (key == KEY_D)
		fcam_move(frac->fcam, 1, 0);
	if (key == KEY_A)
		fcam_move(frac->fcam, -1, 0);
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
