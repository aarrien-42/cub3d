/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/25 13:25:15 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	render(t_data *data)
{
	int		px = data->px, py = data->py;
	double	ra;
	double	d;
	int		i;
	int		x;

	i = 0;
	x = 0;
	draw_back(data);
	printf("\n\n================================\n\n");
	while (i < RAYS)
	{
		if (data->pa < 0)
			data->pa += 2 * M_PI;
		if (data->pa > 2 * M_PI)
			data->pa -= 2 * M_PI;
		ra = data->pa - (FOV / 2) + (FOV / RAYS * i);
		if (ra < 0)
			ra += 2 * M_PI;
		if (ra > 2 * M_PI)
			ra -= 2 * M_PI;
		printf("RA = %f deg (%f rad)\n", rad_to_deg(ra), ra);
		printf("NORMALIZED = %f deg (%f rad)\n", rad_to_deg(normalize(ra)), normalize(ra));
		d = raycast(ra, px, py, data);
		//printf("rayos por cada x = %f\n", (double)WIDTH / RAYS);
		printf("wall distance = %f\n---------------------\n", d);
		while (1)
		{
			//printf("camerax = %d and rays nº %d\n", x, i);
			draw_column(data, x, 30000 / d);
			x++;
			if (x % (WIDTH / RAYS) == 0)
				break;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	mlx_string_put(data->mlx, data->win, 50, 50, 0x00FFFFFF, ft_itoa((int)rad_to_deg(data->pa)));
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
	mlx_hook(data.win, 17, 0, &handle_destroy, &data);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_loop(data.mlx);
	return (0);
}
