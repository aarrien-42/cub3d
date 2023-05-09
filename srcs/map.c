/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 21:03:47 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/09 20:09:13 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	error_map(char **line, int i, t_data *data)
{
	int	j;

	j = -1;
	while (line[i][++j])
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

void	read_map(t_data *data)
{
	int		i;
	int		end;
	size_t	c_line;
	char	**line;

	line = data->t_map->map;
	if (!line)
	{
		printf("Error: No hay mapa\n");
		ft_texture_free(data->t_map, 1);
	}
	end = 0;
	i = -1;
	while (line[++i])
	{
		c_line = check_spaces(line[i]);
		if (end == 0 && ft_strlen(line[i]) == c_line)
			end = 1;
		if (end == 1)
			error_map(line, i, data);
	}
}

int	cont_player(char **line, t_data *data)
{
	int	i;
	int	j;
	int	cont;

	cont = 0;
	i = -1;
	while (line[++i])
	{
		j = -1;
		while (line[i][++j])
		{
			if (line[i][j] == 'N' || line[i][j] == 'S' \
				|| line[i][j] == 'E' || line[i][j] == 'W')
			{
				cont ++;
				data->t_map->player = line[i][j];
			}
		}
	}
	return (cont);
}

void	check_player(t_data *data)
{
	int	cont;

	cont = cont_player(data->t_map->map, data);
	if (cont != 1)
	{
		if (cont == 0)
			printf("Error: No hay jugador en el mapa\n");
		if (cont > 1)
			printf("Error: Hay mas de un jugador en el mapa\n");
		split_free(data->t_map->map);
		ft_texture_free(data->t_map, 1);
	}
}

void	validate_map(t_data	*data)
{
	int		size;
	int		i;
	char	**line;

	line = data->t_map->map;
	size = -1;
	while (line[++size])
		;
	i = 0;
	if (line[0])
		first_line(line, data);
	while (++i < size - 2)
	{
		first_character(line, i, data);
		if (check_spaces(line[i + 1]) == ft_strlen(line[i + 1]))
			break ;
		check_character(line, i, data);
	}
	if (line[i])
	{
		if (before_lastline(line, i, data))
			check_character(line, i, data);
		last_line(line, ++i, data);
	}
}
