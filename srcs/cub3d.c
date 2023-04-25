/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/25 20:10:05 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void init_map(t_map *map)
{
	map->SO_img = NULL;
	map->NO_img = NULL;
	map->EA_img = NULL;
	map->WE_img = NULL;
}

int	render(t_data *data)
{
	int i;

	i = 0;
	draw_back(data);
	while (i < WIDTH)
	{
		draw_column(data, i, HEIGHT - i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	return (0);
}

void	init_values(t_data *data)
{
	data->h_line = HEIGHT/2; // horizon line
}

int main(int argc, char **argv)
{
	(void)argc;
	t_data		data;

	data.t_map = (t_map *)malloc(sizeof(t_map));
	init_map(data.t_map);
	check_file(argv[1], &data);
/*	init_values(&data);
 	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	data.image = mlx_new_image (data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.size, &data.endian);
	mlx_hook(data.win, 2, (1L << 0), &handle_keypress, &data);
	mlx_hook(data.win, 17, 0, &handle_destroy, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx); */
	return (0);
}
