/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:54:25 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/01 19:14:08 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	first_line(char **line, t_data *data)
{
	int	j;

	j = -1;
	while (line[0][++j])
	{
		if (line[0][j] != '1' && line[0][j] != '\n' && line[0][j] != ' ')
		{
			printf("Error: Mapa invalido\nPrimera linea(borrar luego)\n");
			split_free(data->t_map->map);
			ft_texture_free(data->t_map, 1);
		}
	}
}

void	first_character(char **line, int i, t_data *data)
{
	if (line[i][0] == '0' || line[i][0] == 'N' || line[i][0] == 'E' \
		|| line[i][0] == 'W' || line[i][0] == 'S')
	{
		printf("Error: Mapa invalido\nprimer caracter mal\n");
		split_free(data->t_map->map);
		ft_texture_free(data->t_map, 1);
	}	
}

void	check_character(char **line, int i, t_data *data)
{
	int	j;

	j = -1;
	while (line[i][++j])
	{
		if ((line[i][j] == '0' || line[i][j] == 'N' || line[i][j] == 'E' \
			|| line[i][j] == 'W' || line[i][j] == 'S')
			&& ((line[i][j + 1] == ' ' || line[i][j + 1] == '\n') \
			|| line[i][j - 1] == ' ' \
			|| (line[i + 1][j] == ' ' || line[i + 1][j] == '\n') \
			|| line[i - 1][j] == ' ' ))
		{
			printf("Error: Mapa invalido\nno esta cerrado\n");
			split_free(data->t_map->map);
			ft_texture_free(data->t_map, 1);
		}
	}
}

void	last_line(char **line, int i, t_data *data)
{
	int	j;

	j = -1;
	while (line[i][++j])
	{
		if (line[i][j] != '1' && line[i][j] != '\n' && line[i][j] != ' ')
		{
			printf("Error: Mapa invalido\nUltima linea(borrar luego)\n");
			split_free(data->t_map->map);
			ft_texture_free(data->t_map, 1);
		}
	}
}
