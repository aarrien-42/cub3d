/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/02 17:59:19 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	show_map(t_data *data)
{
	int	xy[2];

	xy[1] = 0;
	while (xy[1] < data->t_map->map_h)
	{
		xy[0] = 0;
		while (xy[0] < (int)ft_strlen(data->t_map->map[xy[1]]))
		{
			if (data->t_map->map[xy[1]][xy[0]] == '1')
				draw_rect(xy, MAP_PIXEL, encode_rgb(0, 0, 0), data);
			if (xy[0] == (int)data->px / UNIT && xy[1] == (int)data->py / UNIT)
				draw_rect(xy, MAP_PIXEL, encode_rgb(255, 255, 255), data);
			xy[0]++;
		}
		xy[1]++;
	}
}

void	init_map(t_map *map)
{
	map->so_img = NULL;
	map->no_img = NULL;
	map->ea_img = NULL;
	map->we_img = NULL;
}

int	render(t_data *data)
{
	double	ra;
	double	d;
	int		x;

	x = 0;
	draw_back(data);
	while (x < WIDTH)
	{
		data->pa = fix_angle(data->pa);
		ra = fix_angle(data->pa + (FOV / 2) - (FOV / WIDTH * x));
		d = raycast(ra, data->px, data->py, data);
		draw_column(data, x, (UNIT / d) * ((WIDTH / 2) / tan(FOV / 2)));
		x++;
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
	int	j;
	int	i;

	j = -1;
	while (data->t_map->map[++j])
	{
		i = -1;
		while (data->t_map->map[j][++i])
		{
			if (data->t_map->map[j][i] == data->t_map->player)
			{
				data->px = i * UNIT + UNIT / 2;
				data->py = j * UNIT + UNIT / 2;
			}
		}
	}
	data->t_map->map_h = j;
	if (data->t_map->player == 'N')
		data->pa = 1 * (M_PI / 2);
	else if (data->t_map->player == 'S')
		data->pa = 3 * (M_PI / 2);
	else if (data->t_map->player == 'E')
		data->pa = 0 * (M_PI / 2);
	else if (data->t_map->player == 'W')
		data->pa = 2 * (M_PI / 2);
	data->h_line = HEIGHT / 2;
}

int main(int argc, char **argv)
{
	(void)argc;
	t_data		data;

	data.t_map = (t_map *)malloc(sizeof(t_map));
	if(!data.t_map)
	{
		perror("Malloc");
		return (-1);
	}
 	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	init_map(data.t_map);
	check_file(argv[1], &data);
	init_values(&data);
	data.image = mlx_new_image (data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.size, &data.endian);
 	render(&data);
	mlx_hook(data.win, 2, (1L << 0), &handle_keypress, &data);
	mlx_hook(data.win, 3, (1L << 1), &handle_keyrelease, &data);
	mlx_hook(data.win, 17, 0, &handle_destroy, &data);
	mlx_loop_hook(data.mlx, &loop, &data);
	mlx_loop(data.mlx);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
