/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:51:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/02/16 22:51:06 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ll3d.h"
# include "mlx.h"

# define SCREEN_X			1920
# define SCREEN_Y			1080
# define SCREEN_NAME		"Fract'ol"
# define DEFAULT_MAX_ITERS	256

# define KEY_ESC			53

typedef struct	s_fractol
{
	t_mlx		*mlx;
	short		*map;
	size_t		max_iters;
	size_t		center_x;
	size_t		center_y;
	size_t		size_x;
	size_t		size_y;
}				t_fractol;

int			hook_key(const int key, t_fractol *frac);

t_fractol	*fractol_init(const size_t size_x, const size_t size_y);
void		fractol_free(t_fractol **frac);

#endif
