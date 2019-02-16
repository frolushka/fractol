/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlmscount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:42:32 by edraugr-          #+#    #+#             */
/*   Updated: 2019/02/16 17:21:59 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dlmscount(const char *str, const char *dlms)
{
	int	res;

	res = 0;
	while (ft_checkdlms(str[res], dlms) && str[res])
		res++;
	if (!str[res])
		return (-1);
	return (res);
}
