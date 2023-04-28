/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:03:47 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/28 21:32:51 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_map(t_data *data)
{
	int	i;
	int	j;
	int end;
	size_t c_line;
	char **line;
	
	line = data->t_map->map;
	end = 0;
	i = -1;
	while(line[++i])
	{
		c_line = check_spaces(line[i]);
		if (end == 0 && ft_strlen(line[i]) == c_line)
			end = 1;
		if(end == 1)
		{
			j = -1;
			while(line[i][++j])
			{
				if (line[i][j] != '\t' && line[i][j] != '\n' && line[i][j] != '\v'\
					&&line[i][j] != '\f' && line[i][j] != '\r' && line[i][j] != ' ')
					{
						printf("Error: Archivo Invalido\n");
						split_free(line);
						ft_texture_free(data->t_map, 1);
					}
			}
		}
	}
}