/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 22:01:03 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 22:39:02 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_free(t_fractol **frac)
{
	if (!frac || !*frac)
		return ;
	mlx_free_ll3d(&((*frac)->mlx));
	free((*frac)->map);
	free(*frac);
	*frac = NULL;
}
