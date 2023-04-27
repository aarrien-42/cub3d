/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:35:08 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/27 12:20:44 by aarrien-         ###   ########.fr       */
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
				draw_pixel(data, i, j, encode_rgb(255, 100, 0));
			else
				draw_pixel(data, i, j, encode_rgb(255, 255, 100));
			i++;
		}
		j++;
	}
}