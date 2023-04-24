/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:42:25 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/24 20:44:57 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_texture(char *img_dir, char *token)
{
	int	fd;

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

void	save_texture(char **img_dir, char *token, t_map *map)
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
}
