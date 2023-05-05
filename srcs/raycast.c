/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:31 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/05 12:28:16 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	calc_col_v_data(double ra, int px, int py, t_colision *c)
{
	if (ra < M_PI)
	{
		c->cy = py / UNIT * UNIT;
		c->iy = -UNIT;
	}
	else
	{
		c->cy = py / UNIT * UNIT + UNIT;
		c->iy = UNIT;
	}
	if (ra < M_PI / 2 || ra > 3 * M_PI / 2)
	{
		c->cx = px + (fabs(c->cy - py) / tan(normalize(ra)));
		c->ix = fabs(c->iy / tan(normalize(ra)));
	}
	else
	{
		c->cx = px - (fabs(c->cy - py) / tan(normalize(ra)));
		c->ix = -fabs(c->iy / tan(normalize(ra)));
	}
	if (ra < M_PI)
		c->cy--;
	return (0);
}

t_colision	col_v(double ra, int px, int py, t_data *data)
{
	t_colision	c;

	if (ra == (2 * M_PI) || ra == M_PI || ra == 0)
		return (c.dist = 1e30, c);
	calc_col_v_data(ra, px, py, &c);
	while (1)
	{
		if (leave_map(data, &c) == 1)
			return (c.dist = 1e30, c);
		if (data->t_map->map[(int)(c.cy / UNIT)][(int)(c.cx / UNIT)] == '1')
			return (c.dist = distance(data->px, data->py, c.cx, c.cy), c);
		c.cx += c.ix;
		c.cy += c.iy;
	}
}

int	calc_col_h_data(double ra, int px, int py, t_colision *c)
{
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
	{
		c->cx = px / UNIT * UNIT;
		c->ix = -UNIT;
	}
	else
	{
		c->cx = px / UNIT * UNIT + UNIT;
		c->ix = UNIT;
	}
	if (ra < M_PI)
	{
		c->cy = py - (fabs(c->cx - px) * tan(normalize(ra)));
		c->iy = -fabs(c->ix * tan(normalize(ra)));
	}
	else
	{
		c->cy = py + (fabs(c->cx - px) * tan(normalize(ra)));
		c->iy = fabs(c->ix * tan(normalize(ra)));
	}
	if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
		c->cx--;
	return (0);
}

t_colision	col_h(double ra, int px, int py, t_data *data)
{
	t_colision	c;

	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (c.dist = 1e30, c);
	calc_col_h_data(ra, px, py, &c);
	while (1)
	{
		if (leave_map(data, &c) == 1)
			return (c.dist = 1e30, c);
		if (data->t_map->map[(int)(c.cy / UNIT)][(int)(c.cx / UNIT)] == '1')
			return (c.dist = distance(data->px, data->py, c.cx, c.cy), c);
		c.cx += c.ix;
		c.cy += c.iy;
	}
}

t_colision	raycast(double ra, int px, int py, t_data *data)
{
	t_colision	ch;
	t_colision	cv;

	ch = col_h(ra, px, py, data);
	cv = col_v(ra, px, py, data);
	if (ch.dist < cv.dist)
	{
		if (ra > M_PI / 2 && ra < 3 * M_PI / 2)
			ch.texture = data->t_map->we_img;
		else
			ch.texture = data->t_map->ea_img;
		ch.dist = ch.dist * cos(fabs(ra - data->pa));
		return (ch);
	}
	else
	{
		if (ra < M_PI)
			cv.texture = data->t_map->no_img;
		else
			cv.texture = data->t_map->so_img;
		cv.dist = cv.dist * cos(fabs(ra - data->pa));
		return (cv);
	}
}
