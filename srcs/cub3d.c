/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:54:51 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/27 13:18:26 by aarrien-         ###   ########.fr       */
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

void	show_info(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 10, 20, 0x00FFFFFF, ft_itoa((int)rad_to_deg(data->pa)));
	mlx_string_put(data->mlx, data->win, 10, 30, 0x00FFFFFF, "x:");
	mlx_string_put(data->mlx, data->win, 30, 30, 0x00FFFFFF, ft_itoa(data->px));
	mlx_string_put(data->mlx, data->win, 10, 40, 0x00FFFFFF, "y:");
	mlx_string_put(data->mlx, data->win, 30, 40, 0x00FFFFFF, ft_itoa(data->py));
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
		ra = fix_angle(data->pa - (FOV / 2) + (FOV / WIDTH * i));
		d = raycast(ra, data->px, data->py, data);
		draw_column(data, i, (UNIT / d) * ((WIDTH / 2) / tan(FOV / 2)));
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
	show_info(data);
	move_gestor(0, data);
	rotate_gestor(0, data);
	return (0);
}

void	init_values(t_data *data)
{
	data->h_line = HEIGHT/2; // horizon line
	data->pa = 0 * (M_PI / 180);
	data->map_h = 24;
	data->map_w = 24;
	data->px = 160;
	data->py = 160;
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
