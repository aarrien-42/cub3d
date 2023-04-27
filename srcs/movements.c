/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:14:50 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/27 13:30:23 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	move(t_data *data, double angle) // faltan colisones
{
	int map[24][24]= \
	{
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int	step;

	step = 16;
	angle = fix_angle(angle);
	if ((angle < M_PI && map[(int)(data->py - step)/UNIT][(int)data->px/UNIT] == 0) || (angle > M_PI && map[(int)(data->py + step)/UNIT][(int)data->px/UNIT] == 0))
		data->py -= sin(angle) * MOVE_SPEED;
	if (((angle < M_PI / 2 || angle > 3*M_PI/2) && (map[(int)data->py/UNIT][(int)(data->px + step)/UNIT] == 0)) || ((angle > M_PI / 2 && angle < 3*M_PI/2) && (map[(int)data->py/UNIT][(int)(data->px - step)/UNIT] == 0)))
		data->px += cos(angle) * MOVE_SPEED;
	return (0);
}

int	move_gestor(int code, t_data *data)
{
	static int	f;
	static int	b;
	static int	l;
	static int	r;

	if (code == 1 || code == 2)
		f = code % 2;
	if (code == 3 || code == 4)
		b = code % 2;
	if (code == 5 || code == 6)
		l = code % 2;
	if (code == 7 || code == 8)
		r = code % 2;
	if (f == 1)
		move(data, data->pa);
	if (b == 1)
		move(data, data->pa + M_PI);
	if (l == 1)
		move(data, data->pa - M_PI / 2);
	if (r == 1)
		move(data, data->pa + M_PI / 2);
	return (0);
}

int	rotate_gestor(int code, t_data *data)
{
	static int	l;
	static int	r;

	if (code == 1 || code == 2)
		l = code % 2;
	if (code == 3 || code == 4)
		r = code % 2;
	if (l == 1)
		data->pa -= ROTATE_SPEED * (M_PI / 180);
	if (r == 1)
		data->pa += ROTATE_SPEED * (M_PI / 180);
	return (0);
}
