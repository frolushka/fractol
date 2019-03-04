/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 22:24:33 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 18:01:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ll3d.h"

long double	ft_fmin(const long double a, const long double b)
{
	return (a > b ? b : a);
}

int		ft_min(const int a, const int b)
{
	return (a > b ? b : a);
}

long double	ft_fmax(const long double a, const long double b)
{
	return (a < b ? b : a);
}

int		ft_max(const int a, const int b)
{
	return (a < b ? b : a);
}
