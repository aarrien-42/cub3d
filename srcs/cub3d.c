/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/05 11:20:16 by aarrien-         ###   ########.fr       */
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

int	render(t_data *data)
{
	double		ra;
	t_colision	c;
	int			x;
	double		fov;

	fov = M_PI / 3;
	x = 0;
	draw_back(data);
	while (x < WIDTH)
	{
		data->pa = fix_angle(data->pa);
		ra = fix_angle(data->pa + (fov / 2) - (fov / WIDTH * x));
		c = raycast(ra, data->px, data->py, data);
		draw_column(data, c, x, (UNIT / c.dist) * ((WIDTH / 2) / tan(fov / 2)));
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc > 2)
		return (printf("Error\n"), -1);
	data.t_map = (t_map *)malloc(sizeof(t_map));
	if (!data.t_map)
		return (perror("Malloc"), -1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	init_map(data.t_map);
	check_file(argv[1], &data);
	init_values(&data);
	data.image = mlx_new_image (data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.image, \
	&data.bpp, &data.size, &data.endian);
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
