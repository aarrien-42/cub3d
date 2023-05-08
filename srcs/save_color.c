/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:10:57 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/08 16:50:25 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	save_number(char *line, char **split_color, t_data *data)
{
	int	i;

	if (line[0] == 'F')
	{
		i = -1;
		while (++i < 3)
			data->t_map->floor[i] = ft_atoi(split_color[i]);
	}
	if (line[0] == 'C')
	{
		i = -1;
		while (++i < 3)
			data->t_map->ceiling[i] = ft_atoi(split_color[i]);
	}
}

void	cont_coma(char *line, char token, t_data *data, int fd)
{
	int	i;
	int	cont;

	i = 1;
	cont = 0;
	while (line[++i])
	{
		if (line[i] == ',' && (line[i + 1] == ' ' || line[i + 1] == '\n'\
			|| line[i - 1] == ' ') && cont < 2)
		{
			ft_close(fd);
			printf("Error: %c No puede haber espacios en comas\n", token);
			ft_texture_free(data->t_map, 1);
		}
		if (line[i] == ',')
			cont++;
		if (cont == 2 && line[i] == ' ')
			check_fin_color(line, i, fd, data);
	}
	if (cont != 2)
		error_color(token, fd, data);
}

void	check_format(char *line, char token, t_data *data, int fd)
{
	int	i;

	i = 1;
	while (line[++i])
	{
		if (!(line[i] >= '0' && line[i] <= '9') \
			&& line[i] != ',' && line[i] != '\n' && line[i] != ' ')
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
	char	**color_split;
	char	*aux;
	char	*strim;

	check_format(line, token, data, fd);
	cont_coma(line, token, data, fd);
	color_split = ft_split(line, ' ');
	if (color_split[1][ft_strlen(color_split[1]) - 1] == '\n')
		aux = ft_substr(color_split[1], 0, ft_strlen(color_split[1]) - 1);
	else
	{
		strim = ft_strtrim(color_split[1], " ");
		aux = ft_substr(strim, 0, ft_strlen(strim));
		free(strim);
	}
	split_free(color_split);
	color_split = ft_split(aux, ',');
	free(aux);
	cont_number(color_split, token, data, fd);
	check_number(color_split, token, data, fd);
	save_number(line, color_split, data);
	split_free(color_split);
	free(line);
}
