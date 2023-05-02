/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/28 16:43:25 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

double	fix_angle(double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	return (angle);
}

void	show_map(t_data *data)
{
	int	xy[2];

	xy[1] = 0;
	while (xy[1] < data->map_h)
	{
		xy[0] = 0;
		while (xy[0] < data->map_w)
		{
			if (data->t_map->map[xy[1]][xy[0]] != 0)
				draw_rect(xy, MAP_PIXEL, encode_rgb(0, 0, 0), data);
			if (xy[0] == (int)data->px / UNIT && xy[1] == (int)data->py / UNIT)
				draw_rect(xy, MAP_PIXEL, encode_rgb(255, 255, 255), data);
			xy[0]++;
		}
		xy[1]++;
	}
}
void init_map(t_map *map)
{
	map->SO_img = NULL;
	map->NO_img = NULL;
	map->EA_img = NULL;
	map->WE_img = NULL;
}

int	render(t_data *data)
{
	double	ra;
	double	d;
	int		i;

	i = 0;
	draw_back(data);
	while (i < WIDTH)
	{
		data->pa = fix_angle(data->pa);
		ra = fix_angle(data->pa + (FOV / 2) - (FOV / WIDTH * i));
		d = raycast(ra, data->px, data->py, data);
		draw_column(data, i, (UNIT / d) * ((WIDTH / 2) / tan(FOV / 2)));
		i++;
	}
	show_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	return (0);
}

int	loop(t_data *data)
{
	if (move_gestor(0, data) == 1)
		render(data);
	if (rotate_gestor(0, data) == 1)
		render(data);
	return (0);
}

void	init_values(t_data *data)
{
	data->h_line = HEIGHT / 2;
	data->pa = 0 * (M_PI / 180);
	data->map_h = 24;
	data->map_w = 24;
	data->px = 96;
	data->py = 96;
}

int main(int argc, char **argv)
{
	(void)argc;
	t_data		data;

	data.t_map = (t_map *)malloc(sizeof(t_map));
	if(!data.t_map)
	{
		perror("Malloc");
		return(-1);
	}
	init_map(data.t_map);
	check_file(argv[1], &data);
	init_values(&data);
 	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	data.image = mlx_new_image (data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.size, &data.endian);
	//render(&data);
	mlx_hook(data.win, 2, (1L << 0), &handle_keypress, &data);
	mlx_hook(data.win, 3, (1L << 1), &handle_keyrelease, &data);
	mlx_hook(data.win, 17, 0, &handle_destroy, &data);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
