/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:01:54 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/28 16:51:28 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	size_map(char *line, int fd, t_data *data)
{
	int	size;

	size = 0;
	while(1)
	{
		line = get_next_line(fd);
		printf("line:%s", line);
		if(!line)
			break;
		size ++;
	}
	data->t_map->map = (char **) malloc (size * sizeof(char *));
	if(!data->t_map->map)
	{
		perror("Error Map Malloc");
		exit(-1);
	}
	ft_close(fd);
	printf("\nsize: %d\n", size);
}

void	map_location(char *line, int fd, t_data *data)
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
		size_map(line, fd, data);
}

void	search_map(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	int		cont;
/* 	int		i;
	size_t	c_line; */
	
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
		{
			map_location(line, fd, data);
/* 			c_line = 0;
			i = -1;
			while (line[++i])
				if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v'\
					|| line[i] == '\f' || line[i] == '\r' || line[i] == ' ')
					c_line++;
			if (ft_strlen(line) != c_line)
				size_map(line, fd, data); */
		}
	}
}

void	save_map(char *argv, t_data *data)
{
	search_map(argv, data);
}