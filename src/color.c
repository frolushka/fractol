/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:33:56 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/04 18:39:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int get_color(int it, t_frac *f)
{
    int i;

    i = -1;
    while (++i < 6)
    {
        if (it >= f->colors[0][i] && it < f->colors[0][i + 1])
            return (f->lerp ?
                color_lerp(f->colors[1][i], f->colors[1][i + 1],
                    (f->colors[1][i + 1] - f->colors[1][i + 1]) / 32.0) :
                f->colors[1][i]);
    }
    return (f->colors[1][7]);
}