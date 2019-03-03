/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:33:53 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/03 02:59:55 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac	*frac_init(const float r, const ushort its)
{
	t_frac	*res;

	if (!(res = (t_frac *)malloc(sizeof(t_frac))))
		return (NULL);
	res->mlx = NULL;
	res->fcam = NULL;
	res->its = its;
	res->r = r;
	res->tc = THREADS_COUNT;
	return (res);
}

t_frac	*frac_delete(t_frac **frac)
{
	fmlx_delete(&((*frac)->mlx));
	fcam_delete(&((*frac)->fcam));
	ft_memdel((void **)frac);
	return (*frac);
}

// t_tfrac	*tfrac_init(pthread_t i, t_frac *f)
// {
// 	t_tfrac	*res;

// 	if (!(res = (t_tfrac *)malloc(sizeof(t_tfrac))))
// 		return (NULL);
// 	res->i = i;
// 	res->f = f;
// 	return (res);
// }