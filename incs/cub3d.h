/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/27 13:01:35 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <math.h>
# include "../incs/libft.h"
# include "../mlx/mlx.h"

#define HEIGHT 1080
#define WIDTH 1920
#define FOV M_PI/3
#define UNIT 64
#define MOVE_SPEED 5
#define ROTATE_SPEED 5

int	color;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*image;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
	int			**map;
	int			h_line;
	int			map_w;
	int			map_h;
	double		pa;
	double		px;
	double		py;
}				t_data;

typedef struct s_colision {
	double		cx;
	double		cy;
	double		ix;
	double		iy;
}				t_colision;

/*-CUB3D-*/
double	fix_angle(double angle);
int		render(t_data *data);
void	init_values(t_data *data);

/*-EVENTS-*/
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_destroy(t_data *data);

/*-DRAW-*/
int		encode_rgb(int red, int green, int blue);
void	draw_pixel(t_data *data, int x, int y, int color);
void	draw_column(t_data *data, int x, int h);
void	draw_back(t_data *data);

/*-MOVEMENTS-*/
int		move(t_data *data, double angle);
int		move_gestor(int code, t_data *data);
int		rotate_gestor(int code, t_data *data);

/*-RAYCAST-*/
double	normalize(double angle);
double	rad_to_deg(double angle);
double	col_v(double ra, int px, int py, t_data *data);
double	col_h(double ra, int px, int py, t_data *data);
int		raycast(double ra, int px, int py, t_data *data);

#endif
