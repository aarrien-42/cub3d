/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:53:07 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/24 20:43:24 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* int open_texture(char *img_dir, char *token)
{
	int fd;

	printf("open_dir: %s\n", img_dir);
	fd = open(img_dir, O_RDONLY);
	if( fd == -1)
	{
		printf("Error: Textura %s es erronea", token);
		free(img_dir);
		return(fd);
	}
	ft_close(fd);
	return(fd);
}

void save_texture(char **img_dir, char *token, t_map *map)
{
	if (!ft_strncmp(img_dir[0], "NO", 2))
	{
		map->NO_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		if(open_texture(map->NO_img, token) == -1)
			exit (-1);
		printf("img_dir: %smap: %s\n", img_dir[1], map->NO_img);
	}
	else if (!ft_strncmp(img_dir[0], "SO", 2))
	{
		map->SO_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		if(open_texture(map->SO_img, token) == -1)
			exit (-1);
		printf("img_dir: %smap: %s\n", img_dir[1], map->SO_img);
	}
	else if (!ft_strncmp(img_dir[0], "WE", 2))
	{
		map->WE_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		if(open_texture(map->WE_img, token) == -1)
			exit (-1);
		printf("img_dir: %smap: %s\n", img_dir[1], map->WE_img);
	}
	else if (!ft_strncmp(img_dir[0], "EA", 2))
	{
		map->EA_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		if(open_texture(map->EA_img, token) == -1)
			exit (-1);
		printf("img_dir: %smap: %s\n", img_dir[1], map->EA_img);
	}
}

void	get_image(char *line, char *token, t_map *map)
{
	//int fd;
	char **img_dir;
	(void)token;
	
	img_dir = ft_split(line, ' ');
	save_texture(img_dir, token, map);
} */

void	save_token(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	
	fd = ft_open(argv);
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		if (line[0] == 'N' && line[1] == 'O' )
			get_image(line, "NO", map);
		else if (line[0] == 'S' && line[1] == 'O')
			get_image(line, "SO", map);
		else if (line[0] == 'W' && line[1] == 'E')
			get_image(line, "WE", map);
		else if (line[0] == 'E' && line[1] == 'A')
			get_image(line, "EA", map);
/* 		else if (line[0] == 'F')
			get_color(line, 'F');
		else if (line[0] == 'C')
			get_color(line, 'F'); */
	}
	ft_close(fd);
}

void	map(char *line, int fd)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'\
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'\
			&& line[i] != ' ' && line[i] != '\n')
		{
			printf("Error: Archivo no valido\n");
			ft_close(fd);
			exit(-1);
		}
	}		
}

void	cont_token(char *argv)
{
	int		fd;
	char	*line;
	size_t	c_line;
	int		cont;
	int		i;

	cont = 0;
	fd = ft_open(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		c_line = 0;
		i = -1;
		while (line[++i])
			if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v'\
				|| line[i] == '\f' || line[i] == '\r' || line[i] == ' ')
				c_line++;
		if (ft_strlen(line) != c_line)
			cont ++;
		if (cont > 6)
			map(line, fd);
	}
	ft_close(fd);
}

void	check_map(char *argv, t_map *map)
{
	cont_token(argv);
	save_token(argv, map);
}
