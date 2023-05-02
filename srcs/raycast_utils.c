/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:50:04 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/02 15:10:47 by aarrien-         ###   ########.fr       */
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

double	normalize(double angle)
{
	if (angle <= M_PI / 2)
		return (angle);
	else if (angle <= M_PI)
		return (M_PI - angle);
	else if (angle <= 3 * M_PI / 2)
		return (angle - M_PI);
	else
		return (2 * M_PI - angle);
}

double	rad_to_deg(double angle)
{
	return (angle * 180 / M_PI);
}

double	distance(int px, int py, int cx, int cy)
{
	return (sqrt(pow(abs(px - cx), 2) + pow(abs(py - cy), 2)));
}

int	leave_map(t_data *data, t_colision	*c)
{
	int	line_len;

	if (c->cy / UNIT < 0 || \
		c->cy / UNIT > data->t_map->map_h - 1)
		return (1);
	line_len = (int)ft_strlen(data->t_map->map[(int)c->cy / UNIT]);
	if (c->cx / UNIT < 0 || \
		c->cx / UNIT > line_len - 1)
		return (1);
	return (0);
}
