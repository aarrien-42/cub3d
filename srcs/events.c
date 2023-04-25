/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:23 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/25 13:33:28 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
		handle_destroy(data);
	if (keysym == 13)
	{
		data->px += cos(data->pa) * 2;
		data->py -= sin(data->pa) * 2;
		printf("forward\n");
	}
	if (keysym == 0)
	{
		data->px += cos(data->pa - M_PI/2) * 2;
		data->py -= sin(data->pa - M_PI/2) * 2;
		printf("left\n");
	}
	if (keysym == 1)
	{
		data->px += cos(data->pa + M_PI) * 2;
		data->py -= sin(data->pa + M_PI) * 2;
		printf("back\n");
	}
	if (keysym == 2)
	{
		data->px += cos(data->pa + M_PI/2) * 2;
		data->py -= sin(data->pa + M_PI/2) * 2;
		printf("right\n");
	}
	if (keysym == 123)
	{
		data->pa -= 5 * (M_PI / 180);
		printf("view left\n");
	}
	if (keysym == 124)
	{
		data->pa += 5 * (M_PI / 180);
		printf("view right\n");
	}
	return (0);
}

int	handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}