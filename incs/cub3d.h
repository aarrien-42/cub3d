/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/28 16:38:30 by aarrien-         ###   ########.fr       */
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

#define HEIGHT 640
#define WIDTH 1080
#define FOV M_PI/3
#define UNIT 64
#define MOVE_SPEED 3
#define ROTATE_SPEED 3
#define MAP_PIXEL 4

int	color;

typedef struct s_data {
	void			*mlx;
	void			*win;
	void			*image;
	char			*addr;
	int				bpp;
	int				size;
	int				endian;
	int				h_line;
	int				map_w;
	int				map_h;
	double			pa;
	double			px;
	double			py;
	struct s_map	*t_map;
}					t_data;

typedef struct s_colision {
	double		cx;
	double		cy;
	double		ix;
	double		iy;
}				t_colision;

typedef struct s_map
{
	char	*NO_img;
	char	*SO_img;
	char	*EA_img;
	char	*WE_img;
	int		floor[3];
	int		ceiling[3];
	char	**map;
}			t_map;

/*-CUB3D-*/
double	fix_angle(double angle);
void	show_map(t_data *data);
int		render(t_data *data);
int		loop(t_data *data);
void	init_values(t_data *data);

/*-EVENTS-*/
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
int		handle_destroy(t_data *data);

/*-DRAW-*/
int		encode_rgb(int red, int green, int blue);
void	draw_pixel(t_data *data, int x, int y, int color);
void	draw_rect(int *oxy, int dim, int color, t_data *data);
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

/*-CHECK_FILE-*/
int		check_file(char *argv, t_data *data);
void	check_token(char *argv);
int		token(char *argv, char *token);
int		repeated_or_null(int *cont, char *token);
void	check_extension(const char *argv, const char *ext);

/*-CHECK_MAP-*/
void	check_map(char *argv, t_data *data);
void	cont_token(char *argv);
void	map(char *line, int fd);

/*-CHECK_UTILS-*/
int		ft_open(char *argv);
int		ft_close(int fd);
void	split_free(char **str);
void	open_texture(char *dir, char *token, t_map *map, int fd2);
int		img_ext(char *img, char *ext, char *token, int fd);

/*-CHECK_UTILS2*/
int		check_texture(char *txt, char **dir, char *aux, int fd);
void	check_number(char **split_color, char token, t_data *data, int fd);
void	cont_number(char **split_color, char token, t_data *data, int fd);
void	check_fin_color(char *line, int i, int fd, t_data *data);
void	error_color(char token, int fd, t_data *data);

/*-SAVE_TEXTURE*/
void	get_image(char *line, char *token, t_data *data, int fd);
void	save_texture(char **dir, char *token, t_data *data, int fd);
void	open_check_ext(char *texture, char *token, t_map *map, int fd);
void	get_texture(char **dir, char *aux, t_data *data, int fd);
int		check_texture(char *txt, char **dir, char *aux, int fd);

/*-SAVE_COLOR*/
void	get_color(char *line, char token, t_data *data, int fd);
void	check_format(char *line, char token, t_data *data, int fd);
void	cont_coma(char *line, char token, t_data *data, int fd);
void	check_number(char **split_color, char token, t_data *data, int fd);
void	save_number(char *line, char **split_color, t_data *data);

/*-SAVE_MAP-*/
void	save_map(char *argv, t_data *data);

/*-FREE_EXIT*/
void	ft_texture_free(t_map *map, int flag);
#endif
