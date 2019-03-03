/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:51:59 by sbednar           #+#    #+#             */
/*   Updated: 2019/03/03 03:04:21 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "libft.h"
# include "ll3d.h"
# include "mlx.h"

# define SCREEN_NAME		"Fract'ol"

# define DEFAULT_MAX_ITERS	255
# define DEFAULT_MAX_RADIUS	2.0f
# define DEFAULT_MSPEED		0.01f
# define DEFAULT_SSPEED		2.0f

# define THREADS_COUNT		16

# define MODE_MANDELBROT	0
# define MODE_JULIA			1
# define MODE_SHIP			2
# define MODE_RADIO			3
# define MODE_COUNT			4

# define MOUSE_KEY_LEFT		1
# define MOUSE_KEY_RIGHT	2

# define KEY_Q				12
# define KEY_W				13
# define KEY_E				14
# define KEY_R				15
# define KEY_T				17
# define KEY_Y				16
# define KEY_U				32
# define KEY_I				34
# define KEY_O				31
# define KEY_P				35
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_F				3
# define KEY_G				5
# define KEY_H				4
# define KEY_J				38
# define KEY_K				40
# define KEY_L				37
# define KEY_Z				6
# define KEY_X				7
# define KEY_C				8
# define KEY_V				9
# define KEY_B				11
# define KEY_N				45
# define KEY_M				46

# define KEY_ESC			53
# define KEY_ARROWL			123
# define KEY_ARROWR			124
# define KEY_ARROWD			125
# define KEY_ARROWU			126
# define KEY_1				83
# define KEY_2				84
# define KEY_3				85
# define KEY_4				86
# define KEY_5				87
# define KEY_6				88
# define KEY_7				89
# define KEY_8				91

typedef unsigned short		ushort;

typedef struct	s_fcam
{
	float		coord[3];
	char		mode;
	float		mspeed;
	float		sspeed;
}				t_fcam;

typedef struct	s_frac
{
	t_mlx		*mlx;
	t_fcam		*fcam;
	ushort		its;
	float		r;
	int			tc;
}				t_frac;

typedef struct	s_tfrac
{
	short		i;
	t_frac		*f;
}				t_tfrac;

t_fcam	*fcam_init(const char mode, const float mspeed, const float sspeed);
t_fcam	*fcam_delete(t_fcam **fcam);
void	fcam_move(t_fcam *fcam, const float dx, const float dy);
void	fcam_scale(t_fcam *fcam, const float s);

t_frac	*frac_init(const float r, const ushort its);
t_frac	*frac_delete(t_frac **frac);

int		hook_mouse_key(const int key, int x, int y, t_frac *f);
int		hook_key(const int key, t_frac *frac);

t_mlx	*fmlx_delete(t_mlx **mlx);
t_mlx	*fmlx_init(const int width, const int height, char *header);

void	frac_process(t_frac *f);

int		frac_mandelbrot_get_color(t_frac *f, float *p);
int		frac_julia_get_color(t_frac *f, float *p);
int		frac_ship_get_color(t_frac *f, float *p);
int		frac_radio_get_color(t_frac *f, float *p);

#endif
