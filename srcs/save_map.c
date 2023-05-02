/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:01:54 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/02 13:14:56 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	get_map(char *line, int fd, t_data *data)
{
	int	i;

	data->t_map->map[0] = ft_strdup(line);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->t_map->map[++i] = ft_strdup(line);
		free(line);
	}
	data->t_map->map[i + 1] = 0;
}

void	size_map(char *line, int fd, t_data *data)
{
	int	size;

	size = 2;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		size ++;
		free(line);
	}
	data->t_map->map = (char **)malloc(size * sizeof(char *));
	if (!data->t_map->map)
	{
		perror("Error Map Malloc");
		exit(-1);
	}
}

void	map_location(char *line, int fd, t_data *data, int flag)
{
	int		i;
	size_t	c_line;

	c_line = 0;
	i = -1;
	while (line[++i])
		if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v'\
			|| line[i] == '\f' || line[i] == '\r' || line[i] == ' ')
			c_line++;
	if (ft_strlen(line) != c_line)
	{
		if (flag == 0)
			size_map(line, fd, data);
		if (flag == 1)
			get_map(line, fd, data);
	}
}

void	search_map(char *argv, t_data *data, int flag)
{
	int		fd;
	char	*line;
	int		cont;

	cont = 0;
	fd = ft_open(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (cont < 6 && (!ft_strncmp(line, "NO", 2) \
			|| !ft_strncmp(line, "SO", 2) || !ft_strncmp(line, "EA", 2) \
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "F", 1) \
			|| !ft_strncmp(line, "C", 1)))
			cont ++;
		else if (cont == 6)
			map_location(line, fd, data, flag);
		free(line);
	}
	free(line);
	ft_close(fd);
}

void	save_map(char *argv, t_data *data)
{
	search_map(argv, data, 0);
	search_map(argv, data, 1);
	read_map(data);
	check_player(data);
	validate_map(data);
}
