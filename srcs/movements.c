/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:14:50 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/28 16:26:18 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	move(t_data *data, double angle)
{
	int	step;

	step = 16;
	angle = fix_angle(angle);
	if ((angle < M_PI && \
		data->t_map->map[(int)(data->py - step) / UNIT][(int)data->px / UNIT] == '0') || \
		(angle > M_PI && \
		data->t_map->map[(int)(data->py + step) / UNIT][(int)data->px / UNIT] == '0'))
			data->py -= sin(angle) * MOVE_SPEED;
	if (((angle < M_PI / 2 || angle > 3 * M_PI / 2) && \
		(data->t_map->map[(int)data->py / UNIT][(int)(data->px + step) / UNIT] == '0')) || \
		((angle > M_PI / 2 && angle < 3 * M_PI / 2) && \
		(data->t_map->map[(int)data->py / UNIT][(int)(data->px - step) / UNIT] == '0')))
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
		move(data, data->pa + M_PI / 2);
	if (r == 1)
		move(data, data->pa - M_PI / 2);
	return (f == 1 || b == 1 || l == 1 || r == 1);
}

int	rotate_gestor(int code, t_data *data)
{
	static int	l;
	static int	r;
	static int	u;
	static int	d;

	if (code == 1 || code == 2)
		l = code % 2;
	if (code == 3 || code == 4)
		r = code % 2;
	if (code == 5 || code == 6)
		u = code % 2;
	if (code == 7 || code == 8)
		d = code % 2;
	if (l == 1)
		data->pa += ROTATE_SPEED * (M_PI / 180);
	if (r == 1)
		data->pa -= ROTATE_SPEED * (M_PI / 180);
	if (u == 1)
		data->h_line += ROTATE_SPEED * 2;
	if (d == 1)
		data->h_line -= ROTATE_SPEED * 2;
	return (u == 1 || d == 1 || l == 1 || r == 1);
}
