/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll3d.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:56:09 by edraugr-          #+#    #+#             */
/*   Updated: 2019/03/04 18:01:26 by sbednar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LL3D_H
# define LL3D_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>

# define CAM_ISO		0
# define CAM_PER 		1

# define CAM_DSP		5
# define CAM_DSE		1
# define CAM_DFO		1

# define CAM_SP			0.1f
# define CAM_SE			1
# define CAM_FO			0.1f

# define SCREEN_X		1000
# define SCREEN_Y		1000

# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_C			8
# define KEY_Q			12
# define KEY_E			14
# define KEY_F			3
# define KEY_R			15
# define KEY_T			17
# define KEY_ESC		53
# define KEY_ARROWL		123
# define KEY_ARROWR		124
# define KEY_ARROWD		125
# define KEY_ARROWU		126
# define KEY_1			83
# define KEY_2			84
# define KEY_3			85
# define KEY_4			86
# define KEY_5			87
# define KEY_6			88
# define KEY_7			89
# define KEY_8			91
# define KEY_X			7
# define KEY_H			4

# define COLOR_WHITE	0xFFFFFF
# define COLOR_RED		0xFF0000
# define COLOR_GREEN	0x228B22
# define COLOR_BLUE		0x0000FF
# define COLOR_GRAY		0x555555
# define COLOR_LGRAY	0xAAAAAA
# define COLOR_BROWN	0x654321
# define COLOR_BLACK	0x000000

typedef struct			s_vec2
{
	int					x;
	int					y;
}						t_vec2;

typedef struct			s_vec3
{
	long double				x;
	long double				y;
	long double				z;
}						t_vec3;

typedef struct			s_vec4
{
	long double				x;
	long double				y;
	long double				z;
	long double				w;
}						t_vec4;

typedef struct			s_mtx4
{
	long double				val[4][4];
}						t_mtx4;

typedef struct			s_image
{
	void				*image;
	char				*ptr;
	int					bpp;
	int					str;
	int					end;
	int					x;
	int					y;
}						t_image;

typedef struct			s_mlx
{
	int					width;
	int					height;
	t_image				*image;
	void				*mlx;
	void				*win;
}						t_mlx;

typedef struct			s_cam
{
	t_mtx4				*cam;
	t_vec3				*piv;
	int					mode;
	long double				speed;
	long double				ppu;
	long double				sence;
	long double				focus;
	struct s_cam		*add;
}						t_cam;

typedef struct			s_dots
{
	int					i;
	int					xc;
	int					yc;
	int					zmin;
	int					zmax;
	int					cm;
	t_vec4				**wb;
	t_vec3				**cb;
	t_vec2				**sb;
}						t_dots;

t_vec2					*vec2_init(void);
t_vec2					*vec2_new(const int x, const int y);
t_vec2					*vec2_sum(const t_vec2 *v1, const t_vec2 *v2);
t_vec2					*vec2_mult(const t_vec2 *v, const int s);
t_vec2					*vec2_copy(const t_vec2 *v);
void					vec2_set(t_vec2 *v, const int x, const int y);

t_vec3					*vec3_init(void);
t_vec3					*vec3_new(const long double x, const long double y, const long double z);
t_vec3					*vec3_sum(const t_vec3 *v1, const t_vec3 *v2);
t_vec3					*vec3_mult(const t_vec3 *v, const long double s);
t_vec3					*vec3_copy(const t_vec3 *v);
void					vec3_set(t_vec3 *v, const long double x, const long double y,
						const long double z);

t_vec4					*vec4_init(void);
t_vec4					*vec4_new(const long double x, const long double y, const long double z,
						const long double w);
t_vec4					*vec4_sum(const t_vec4 *v1, const t_vec4 *v2);
t_vec4					*vec4_mult(const t_vec4 *v, const long double s);
t_vec4					*vec4_copy(const t_vec4 *v);
t_vec4					**dots4_cpy(const t_vec4 **src, const int xc,
						const int yc);

int						ft_abs(const int x);
int						ft_sign(const long double a);
long double					ft_fabs(const long double x);
void					ft_swap(int *a, int *b);
long double					ft_fmin(const long double a, const long double b);
int						ft_min(const int a, const int b);
long double					ft_fmax(const long double a, const long double b);
int						ft_max(const int a, const int b);

t_mtx4					*mtx4_init(const long double val);
void					mtx4_clear(t_mtx4 *mtx);
t_mtx4					*mtx4_copy(const t_mtx4 *src);
t_mtx4					*mtx4x3_mult(const t_mtx4 *a, const t_mtx4 *b,
						t_mtx4 *dst);
t_mtx4					*mtx4x4_mult(const t_mtx4 *a, const t_mtx4 *b,
						t_mtx4 *dst);
t_mtx4					*mtx4_get_rotation(const long double x, const long double y,
						const long double z, const long double a);

t_cam					*camera_init(void);
void					camera_move_x(t_cam *cam, const long double a);
void					camera_move_y(t_cam *cam, const long double a);
void					camera_move_z(t_cam *cam, const long double a);
void					camera_rotate_x(t_cam *cam, const long double a);
void					camera_rotate_y(t_cam *cam, const long double a);
void					camera_rotate_custom(t_cam *cam, const t_vec3 *p,
						const t_vec3 *axis, const long double a);
void					camera_per_calc_piv(t_cam *cam);

void					dots_fill_cb(const t_vec4 *p, const t_mtx4 *c,
						t_vec3 *res);
void					dots_fill_sb_iso(const t_vec3 *p, t_vec2 *res,
						const long double f);
void					dots_fill_sb_per(const t_vec3 *point, t_vec2 *res,
						const t_cam *cam);
t_dots					*dots_init(const int x, const int y);
void					dots_scale_y(t_dots *dots, const long double s);
void					dots_color_update(t_dots *dots);

void					image_clear(t_image *img);
t_image					*image_init(t_mlx *mlx, const int x, const int y);
void					image_set_pixel(t_image *img, const int x, const int y,
						const int c);
int						image_draw_line(const t_mlx *mlx, const t_vec2 *v1,
						const t_vec2 *v2, const t_vec2 *c);
int						image_draw_line2(const t_mlx *mlx, int *t,
						unsigned short *dt);

t_mlx					*mlx_init_ll3d(const int width, const int height,
						char *header);
t_mlx					*mlx_free_ll3d(t_mlx **mlx);

void					oclude_x(t_vec2 *d1, t_vec2 *d2);
void					oclude_y(t_vec2 *d1, t_vec2 *d2);
void					oclude_z(t_vec2 *d1, t_vec2 *d2, long double z1, long double z2);
void					oclusion_draw_line(const t_mlx *c, t_dots *d,
						int d1, int d2);
int						check_out(const t_dots *d, const int d1, const int d2);
int						swap_if_d2_less(t_vec2 **d1, t_vec2 **d2,
						const long double d1v, const long double d2v);

int						color_lerp(int c1, int c2, long double step);
int						color_get_default(const int z, const int cm);
int						color_set_br(const int c, long double br);

#endif
