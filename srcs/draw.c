/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:35:08 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/28 16:29:13 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	draw_pixel(t_data *data, int x, int y, int color)
{
	char	*pos;

	pos = data->addr + (y * data->size + x * (data->bpp / 8));
	*(unsigned int *)pos = color;
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
			draw_pixel(data, (oxy[0] * MAP_PIXEL) + x + sep, (oxy[1] * MAP_PIXEL) + y + sep, color);
			x++;
		}
		y++;
	}
}

void	draw_column(t_data *data, int x, int h)
{
	int i;

	i = 0;
	while (i < h)
	{
		if (data->h_line - h/2 + i >= 0 && data->h_line - h/2 + i < HEIGHT)
			draw_pixel(data, x, data->h_line - h/2 + i, color);
		i++;
	}
}

void	draw_back(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while(j < HEIGHT)
	{
		i = 0;
		while(i < WIDTH)
		{
			if (j < data->h_line)
				draw_pixel(data, i, j, encode_rgb(data->t_map->ceiling[0], data->t_map->ceiling[1], data->t_map->ceiling[2]));
			else
				draw_pixel(data, i, j, encode_rgb(data->t_map->floor[0], data->t_map->floor[1], data->t_map->floor[2]));
			i++;
		}
		j++;
	}
}