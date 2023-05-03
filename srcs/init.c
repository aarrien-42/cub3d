/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:54:52 by aarrien-          #+#    #+#             */
/*   Updated: 2023/05/03 16:59:26 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	init_map(t_map *map)
{
	map->so_img = NULL;
	map->no_img = NULL;
	map->ea_img = NULL;
	map->we_img = NULL;
}

void	player_orientation(t_data *data)
{
	if (data->t_map->player == 'N')
		data->pa = 1 * (M_PI / 2);
	else if (data->t_map->player == 'S')
		data->pa = 3 * (M_PI / 2);
	else if (data->t_map->player == 'E')
		data->pa = 0 * (M_PI / 2);
	else if (data->t_map->player == 'W')
		data->pa = 2 * (M_PI / 2);
}

void	init_values(t_data *data)
{
	int	j;
	int	i;

	j = -1;
	while (data->t_map->map[++j])
	{
		i = -1;
		while (data->t_map->map[j][++i])
		{
			if (data->t_map->map[j][i] == data->t_map->player)
			{
				data->px = i * UNIT + UNIT / 2;
				data->py = j * UNIT + UNIT / 2;
			}
		}
	}
	data->t_map->map_h = j;
	data->h_line = HEIGHT / 2;
	player_orientation(data);
}
