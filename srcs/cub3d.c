/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/24 15:23:02 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	render(t_data *data)
{
	double posX = 7, posY = 3;
	double dirX = -1, dirY = 0;
	double planeX = 0, planeY = 0.66;
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	double	d;
	int		x;

	x = 0;
	draw_back(data);
	while (x < WIDTH)
	{
		cameraX = 2 * x / (double)WIDTH - 1;
		rayDirX = dirX + (planeX * cameraX);
		rayDirY = dirY + (planeY * cameraX);
		d = raycast(rayDirX, rayDirY, posX, posY);
		printf("wall height = %f\n", d);
		if (d != 0)
			draw_column(data, x, HEIGHT / d);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	return (0);
}

void	init_values(t_data *data)
{
	data->h_line = HEIGHT/2; // horizon line
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
	mlx_hook(data.win, 17, 0, &handle_destroy, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
