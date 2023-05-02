/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:31 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/02 13:24:14 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

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

double	col_v(double ra, int px, int py, t_data *data)
{
	t_colision c;

	if (ra == (2 * M_PI) || ra == M_PI || ra == 0)
		return (1e30);
	calc_col_v_data(ra, px, py, &c);
	while (1)
	{
		if (c.cy / UNIT < 0 || c.cx / UNIT < 0 || c.cy / UNIT > data->t_map->map_h - 1 || c.cx / UNIT > (int)ft_strlen(data->t_map->map[(int)c.cy / UNIT]) - 1)
			return (1e30);
		if (data->t_map->map[(int)(c.cy / UNIT)][(int)(c.cx / UNIT)] == '1')
			return (distance(px, py, c.cx, c.cy));
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

double	col_h(double ra, int px, int py, t_data *data)
{
	t_colision c;

	if (ra == M_PI / 2 || ra == 3 * M_PI / 2)
		return (1e30);
	calc_col_h_data(ra, px, py, &c);
	while (1)
	{
		if (c.cy / UNIT < 0 || c.cx / UNIT < 0 || c.cy / UNIT > data->t_map->map_h - 1 || c.cx / UNIT > (int)ft_strlen(data->t_map->map[(int)c.cy / UNIT]) - 1)
			return (1e30);
		if (data->t_map->map[(int)(c.cy / UNIT)][(int)(c.cx / UNIT)] == '1')
			return (distance(px, py, c.cx, c.cy));
		c.cx += c.ix;
		c.cy += c.iy;
	}
}

// podría devolver una estructura t_colision, y calculariamos la distancia después
int	raycast(double ra, int px, int py, t_data *data)
{
	double	dh;
	double	dv;

	dh = col_h(ra, px, py, data);
	dv = col_v(ra, px, py, data);
	if (dh < dv)
		return (color = encode_rgb(50, 136, 18), dh * cos(fabs(ra - data->pa)));
	else
		return (color = encode_rgb(77, 217, 25), dv * cos(fabs(ra - data->pa)));
	return(0);
}