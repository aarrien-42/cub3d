/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:23 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/19 17:09:07 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
		handle_destroy(data);
	if (keysym == 13)
		printf("forward\n");
	if (keysym == 0)
		printf("left\n");
	if (keysym == 1)
		printf("back\n");
	if (keysym == 2)
		printf("right\n");
	if (keysym == 123)
		printf("view left\n");
	if (keysym == 124)
		printf("view right\n");
	return (0);
}

int	handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}