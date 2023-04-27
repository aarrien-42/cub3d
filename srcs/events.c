/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:59:23 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/27 11:56:25 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

/*int	check_wall(int keysym, t_data *data)
{
	int map[6][11]= \
	{
	  {1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1}
	};
}*/

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == 53)
		handle_destroy(data);
	if (keysym == 13) // forward
		move_gestor(1, data);
	if (keysym == 0) // left
		move_gestor(5, data);
	if (keysym == 1) // back
		move_gestor(3, data);
	if (keysym == 2) // right
		move_gestor(7, data);
	if (keysym == 123) // view left
		rotate_gestor(1, data);
	if (keysym == 124) // view right
		rotate_gestor(3, data);
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == 13)
		move_gestor(2, data);
	if (keysym == 0)
		move_gestor(6, data);
	if (keysym == 1)
		move_gestor(4, data);
	if (keysym == 2)
		move_gestor(8, data);
	if (keysym == 123)
		rotate_gestor(2, data);
	if (keysym == 124)
		rotate_gestor(4, data);
	return (0);
}

int	handle_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}