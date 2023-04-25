/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:10:57 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/25 20:55:15 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_format(char *line, char token, t_data *data)
{
	int i;

	i = 1;
	while(line[++i])
	{
		if(!(line[i] >= '0' && line[i] <= '9')\
			&& line[i] != ',' && line[i] != '\n')
		{
			printf("Error: %c es un dato", line[i]);
			printf(" que no es compatible en %c\n", token);
			ft_texture_free(data->t_map, 1);
		}
	}
}

void	get_color(char *line, char token, t_data *data)
{
	check_format(line, token, data);
}