/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:14:50 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/26 14:39:14 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	move_state(int code)
{
	if (code % 2 == 0)
		return (0);
	else
		return (1);
}

int	move(t_data *data, double angle)
{
	data->px += cos(angle) * MOVE_SPEED;
	data->py -= sin(angle) * MOVE_SPEED;
	return (0);
}

int	move_gestor(int code, t_data *data)
{
	static int	f;
	static int	b;
	static int	l;
	static int	r;

	if (code == 1 || code == 2)
		f = move_state(code);
	if (code == 3 || code == 4)
		b = move_state(code);
	if (code == 5 || code == 6)
		l = move_state(code);
	if (code == 7 || code == 8)
		r = move_state(code);
	if (f == 1)
		move(data, data->pa);
	if (b == 1)
		move(data, data->pa + M_PI);
	if (l == 1)
		move(data, data->pa - M_PI/2);
	if (r == 1)
		move(data, data->pa + M_PI/2);
	return (0);
}

int	rotate_gestor(int code, t_data *data)
{
	static int	l;
	static int	r;

	if (code == 1 || code == 2)
		l = move_state(code);
	if (code == 3 || code == 4)
		r = move_state(code);
	if (l == 1)
		data->pa -= ROTATE_SPEED * (M_PI / 180);
	if (r == 1)
		data->pa += ROTATE_SPEED * (M_PI / 180);
	return (0);
}