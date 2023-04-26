/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:10:57 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/26 20:30:56 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cont_coma(char *line, char token, t_data *data, int fd)
{
	int i;
	int cont;

	i = 1;
	cont = 0;
	while (line[++i])
		if (line[i] == ',')
			cont++;
	if (cont != 2)
	{
		ft_close(fd);
		printf("Error: Formato erroneo en %c", token);
		printf(" solo puede tener dos comas. Ejemplo:0,255,255\n");
		ft_texture_free(data->t_map, 1);
	}
}

void	check_format(char *line, char token, t_data *data, int fd)
{
	int	i;

	i = 1;
	while(line[++i])
	{
		if(!(line[i] >= '0' && line[i] <= '9')\
			&& line[i] != ',' && line[i] != '\n')
		{
			ft_close(fd);
			printf("Error: caracter %c", line[i]);
			printf(" no compatible en %c\n", token);
			ft_texture_free(data->t_map, 1);
		}
	}
}

void	get_color(char *line, char token, t_data *data, int fd)
{
	char **color_split;
	
	check_format(line, token, data, fd);
	cont_coma(line, token, data, fd);
	color_split = ft_split(line, ',');
	cont_number(color_split, token, data, fd);
}