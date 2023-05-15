/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:35:08 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/15 16:44:10 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	draw_pixel(t_data *data, int x, int y, int color)
{
	char	*pos;
	
	if (x < WIDTH && y < HEIGHT)
	{
		pos = data->addr + (y * data->size + x * (data->bpp / 8));
		*(unsigned int *)pos = color;
	}
}

int	get_pixel(t_texture *t, int x, int y)
{
	char	*pos;

	pos = t->addr + (y * t->size + x * (t->bpp / 8));
	return (*(unsigned int *)pos);
}

void	draw_rect(int *oxy, int dim, int color, t_data *data)
{
	int	x;
	int	y;
	int	sep;

	sep = 20;
	y = 0;
	while (y < dim)
	{
		x = 0;
		while (x < dim)
		{
			draw_pixel(data, (oxy[0] * MAP_PIXEL) + x + sep, \
			(oxy[1] * MAP_PIXEL) + y + sep, color);
			x++;
		}
		y++;
	}
}

void	draw_column(t_data *data, t_colision c, int x, int h)
{
	int		i;
	double	scale;

	i = 0;
	scale = (double)UNIT / h;
	while (i < h)
	{
		if (data->h_line - h / 2 + i >= 0 && data->h_line - h / 2 + i < HEIGHT)
		{
			if ((c.cx - ((int)c.cx / UNIT * UNIT)) == 0 || \
			(c.cx - ((int)c.cx / UNIT * UNIT)) == 63)
				draw_pixel(data, x, data->h_line - h / 2 + i, \
				get_pixel(c.texture, \
				(c.cy - ((int)c.cy / UNIT * UNIT)), (scale * i)));
			else
				draw_pixel(data, x, data->h_line - h / 2 + i, \
				get_pixel(c.texture, \
				(c.cx - ((int)c.cx / UNIT * UNIT)), (scale * i)));
		}
		i++;
	}
}

void	draw_back(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (j < data->h_line)
				draw_pixel(data, i, j, encode_rgb(data->t_map->ceiling[0], \
				data->t_map->ceiling[1], data->t_map->ceiling[2]));
			else
				draw_pixel(data, i, j, encode_rgb(data->t_map->floor[0], \
				data->t_map->floor[1], data->t_map->floor[2]));
			i++;
		}
		j++;
	}
}
