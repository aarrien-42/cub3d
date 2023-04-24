/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:57:58 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/24 20:44:39 by jdasilva         ###   ########.fr       */
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
#define CELL_SIZE 32
#define RAYS 300

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*image;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
	char		**map;
	int			h_line;
	int			map_w;
	int			map_h;
}				t_data;

typedef struct s_map
{
	char	*NO_img;
	char	*SO_img;
	char	*EA_img;
	char	*WE_img;
	int		*floor;
	int		*ceiling;
	char	**map;
}			t_map; 

/*-CUB3D-*/
void	init_values(t_data *data);
int		render(t_data *data);

/*-EVENTS-*/
int		handle_keypress(int keysym, t_data *data);
int		handle_destroy(t_data *data);

/*-DRAW-*/
int		encode_rgb(int red, int green, int blue);
void	draw_pixel(t_data *data, int x, int y, int color);
void	draw_column(t_data *data, int x, int h);
void	draw_back(t_data *data);

/*-CHECK_FILE-*/
int		check_file(char *argv, t_map *map);
void	check_token(char *argv);
int		token(char *argv, char *token);
int		repeated_or_null(int *cont, char *token);
void	check_extension(const char *argv, const char *ext);

/*-CHECK_MAP-*/
void	check_map(char *argv, t_map *map);
void	cont_token(char *argv);
void	map(char *line, int fd);

/*-CHECK_UTILS-*/
int		ft_open(char *argv);
int		ft_close(int fd);
void	split_free(char **str);

/*-SAVE_TEXTURE*/
void	get_image(char *line, char *token, t_map *map);
void	save_texture(char **img_dir, char *token, t_map *map);
int		open_texture(char *img_dir, char *token);
#endif
