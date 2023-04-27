/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/27 11:52:01 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	render(t_data *data)
{
	int		px = data->px, py = data->py;
	double	ra;
	double	d;
	int		i;

	i = 0;
	draw_back(data);
	while (i < WIDTH)
	{
		//printf("=============================\nray nº %d\n", i);
		if (data->pa < 0)
			data->pa += 2 * M_PI;
		if (data->pa > 2 * M_PI)
			data->pa -= 2 * M_PI;
		ra = data->pa - (FOV / 2) + (FOV / WIDTH * i);
		if (ra < 0)
			ra += 2 * M_PI;
		if (ra > 2 * M_PI)
			ra -= 2 * M_PI;
		d = raycast(ra, px, py, data);
		draw_column(data, i, (UNIT / d) * ((WIDTH / 2) / tan(FOV / 2)));
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	mlx_string_put(data->mlx, data->win, 10, 20, 0x00FFFFFF, ft_itoa((int)rad_to_deg(data->pa)));
	mlx_string_put(data->mlx, data->win, 10, 30, 0x00FFFFFF, "x:");
	mlx_string_put(data->mlx, data->win, 30, 30, 0x00FFFFFF, ft_itoa((int)rad_to_deg(data->px)));
	mlx_string_put(data->mlx, data->win, 10, 40, 0x00FFFFFF, "y:");
	mlx_string_put(data->mlx, data->win, 30, 40, 0x00FFFFFF, ft_itoa((int)rad_to_deg(data->py)));
	move_gestor(0, data);
	rotate_gestor(0, data);
	//exit(0);
	return (0);
}

void	init_values(t_data *data)
{
	data->h_line = HEIGHT/2; // horizon line
	data->pa = 0 * (M_PI / 180);
	data->px = 96;
	data->py = 96;
}

int main()
{
	t_data	data;

	init_values(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "cub3D");
	data.image = mlx_new_image (data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.image, &data.bpp, &data.size, &data.endian);

	mlx_hook(data.win, 2, (1L << 0), &handle_keypress, &data);
	mlx_hook(data.win, 3, (1L << 1), &handle_keyrelease, &data);
	mlx_hook(data.win, 17, 0, &handle_destroy, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
