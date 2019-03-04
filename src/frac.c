/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:33:53 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:51:38 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac	*frac_init(const long double r, const ushort its)
{
	t_frac	*res;

	if (!(res = (t_frac *)malloc(sizeof(t_frac))))
		return (NULL);
	res->mlx = NULL;
	res->fcam = NULL;
	res->its = its;
	res->r = r;
	res->tc = THREADS_COUNT;
	res->lt = 0;
	res->lerp = 0;
	res->lmx = -1;
	res->lmy = -1;
	return (res);
}

t_frac	*frac_delete(t_frac **frac)
{
	fmlx_delete(&((*frac)->mlx));
	fcam_delete(&((*frac)->fcam));
	ft_memdel((void **)frac);
	return (*frac);
}