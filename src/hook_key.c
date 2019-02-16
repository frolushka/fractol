/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 22:35:33 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 22:37:50 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hook_esc(t_fractol *frac)
{
	fractol_free(&frac);
	exit(0);
}

int			hook_key(const int key, t_fractol *frac)
{
	if (key == KEY_ESC)
		hook_esc(frac);
	return (0);
}
