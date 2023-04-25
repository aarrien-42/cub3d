/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:31 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/25 12:59:54 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	unit = 64;

double	normalize(double angle)
{
	if (angle<= M_PI/2)
		return (angle);
	else if (angle <= M_PI)
		return (M_PI - angle);
	else if (angle <= 3*M_PI/2)
		return (angle - M_PI);
	else
		return (2*M_PI - angle);
}

double	rad_to_deg(double angle)
{
	return (angle*180/M_PI);
}

double	distance(int px, int py, int cx, int cy)
{
	return (sqrt(pow(abs(px - cx), 2) + pow(abs(py - cy), 2)));
}

double	col_v(double ra, int px, int py, t_data *data)
{
	int	cx;
	int	cy;
	int	ix;
	int	iy;
	int map[6][11]= \
	{
	  {1,2,1,2,1,2,1,2,1,2,1},
	  {2,0,0,0,1,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {2,0,0,0,0,0,0,1,0,0,2},
	  {1,1,0,3,0,0,0,0,0,0,2},
	  {1,1,1,1,3,1,2,1,2,1,1}
	};
	(void)data;
	(void)map;

	if (ra == (2 * M_PI) || ra == M_PI)
		return (1e30);
	if (ra < M_PI) // arriba
	{
		cy = py / unit * unit - 1;
		iy = -unit;
	}
	else // abajo
	{
		cy = py / unit * unit + unit;
		iy = unit;
	}
	if (ra < M_PI / 2 || ra > 3*M_PI/2)
	{
		cx = px + (abs(cy - py) / tan(normalize(ra)));
		ix = fabs(iy / tan(normalize(ra)));
	}
	else
	{
		cx = px - (abs(cy - py) / tan(normalize(ra)));
		ix = -fabs(iy / tan(normalize(ra)));
	}
	printf("	V:");
	printf("	cx = %d cy = %d | ix = %d iy = %d\n", cx, cy, ix, iy);
	while (1)
	{
		if (cy/unit < 0 || cx/unit < 0 || cy/unit > data->map_h - 1 || cx/unit > data->map_w - 1)
			return (1e30);
		if (map[cy / unit][cx / unit] != 0)
		{
			printf("	FV:	cx = %d cy = %d\n", cx, cy);
			printf("(ra = %f) posición en mapa (x = %d, y = %d) => [%d]\n", rad_to_deg(ra), cx / unit, cy / unit, map[cy / unit][cx / unit]);
			return (distance(px, py, cx, cy));
		}
		cx += ix;
		cy += iy;
	}
}

double	col_h(double ra, int px, int py, t_data *data)
{
	int	cx;
	int	cy;
	int	ix;
	int	iy;
	int map[6][11]= \
	{
	  {1,2,1,2,1,2,1,2,1,2,1},
	  {2,0,0,0,1,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {2,0,0,0,0,0,0,1,0,0,2},
	  {1,1,0,1,0,0,0,0,0,0,2},
	  {1,1,1,1,2,1,2,1,2,1,1}
	};
	(void)data;
	(void)map;

	if (ra == M_PI / 2 || ra == 3*M_PI/2)
		return (1e30);
	if (ra < M_PI / 2 || ra > 3*M_PI/2) // derecha
	{
		cx = px / unit * unit + unit;
		ix = unit;
	}
	else // izquierda
	{
		cx = px / unit * unit - 1;
		ix = -unit;
	}
	if (ra < M_PI)
	{
		cy = py - (abs(cx - px) * tan(normalize(ra)));
		iy = -fabs(ix * tan(normalize(ra)));
	}
	else
	{
		cy = py + (abs(cx - px) * tan(normalize(ra)));
		iy = fabs(ix * tan(normalize(ra)));
	}
	printf("	H:");
	printf("	cx = %d cy = %d | ix = %d iy = %d\n", cx, cy, ix, iy);
	while (1)
	{
		if (cy/unit < 0 || cx/unit < 0 || cy/unit > data->map_h - 1 || cx/unit > data->map_w - 1)
			return (1e30);
		if (map[cy / unit][cx / unit] != 0)
		{
			printf("	FH:	cx = %d cy = %d\n", cx, cy);
			printf("(ra = %f) posición en mapa (x = %d, y = %d) => [%d]\n", rad_to_deg(ra), cx / unit, cy / unit, map[cy / unit][cx / unit]);
			return (distance(px, py, cx, cy));
		}
		cx += ix;
		cy += iy;
	}
}

int	raycast(double ra, int px, int py, t_data *data)
{
	/*int worldMap[24][24]= \
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
	};*/
	data->map_h = 6;
	data->map_w = 11;
	double	dh;
	double	dv;

	//printf("posición en mapa (x = %d, y = %d) => [%d]\n", px / unit, py / unit, map[py / unit][px / unit]);
	//printf("angulo de rayo = %f\n", ra);
	dh = col_h(ra, px, py, data);
	dv = col_v(ra, px, py, data);
	printf("			DH => %f\n", dh);
	printf("			DV => %f\n", dv);
	if (dh < dv)
		return (color = encode_rgb(77, 217, 25), dh);
	else
		return (color = encode_rgb(50, 136, 18), dv);
	return(0);
}