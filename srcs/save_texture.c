/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:42:25 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/25 20:27:39 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_extension(char *img_dir, char *ext, char *token, t_map *map)
{
	int	len;

	len = ft_strlen(img_dir) - 4;
	if (len < 0)
		len = 0;
	while (*(img_dir + len) && *ext)
	{
		if (*(img_dir + len) != *ext)
		{
			printf ("Error: La textura %s no es .xpm\n", token);
			ft_texture_free(map, 1);
		}
		len++;
		ext++;
	}
}

void	open_texture(char *img_dir, char *token, t_map *map)
{
	int	fd;

	fd = open (img_dir, O_RDONLY);
	if (fd == -1)
	{
		printf("char: %s\n", img_dir);
		printf("Error: Direccion de la textura %s es erronea\n", token);
		ft_texture_free(map, 1);
	}
	ft_close(fd);
}

void	open_check_ext(char *texture, char *token, t_map *map, t_data *data)
{
/* 	int	width;
	int	height; */
	(void) data;

	open_texture(texture, token, map);
	img_extension(texture, ".xpm", token, map);
/* 	if (!mlx_xpm_file_to_image(data->mlx, texture, &width, &height))
	{
		perror("Error");
		ft_texture_free(map, 1);
	} */
}

void	save_texture(char **img_dir, char *token, t_map *map, t_data *data)
{
	if (!ft_strncmp(img_dir[0], "NO", 2))
	{
		map->NO_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		split_free(img_dir);
		open_check_ext(map->NO_img, token, map, data);
	}
	else if (!ft_strncmp(img_dir[0], "SO", 2))
	{
		map->SO_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		split_free(img_dir);
		open_check_ext(map->SO_img, token, map, data);
	}
	else if (!ft_strncmp(img_dir[0], "WE", 2))
	{
		map->WE_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		split_free(img_dir);
		open_check_ext(map->WE_img, token, map, data);
	}
	else if (!ft_strncmp(img_dir[0], "EA", 2))
	{
		map->EA_img = ft_substr(img_dir[1], 0, ft_strlen(img_dir[1]) - 1);
		split_free(img_dir);
		open_check_ext(map->NO_img, token, map, data);
	}
}

void	get_image(char *line, char *token, t_data *data)
{
	char	**img_dir;

	img_dir = ft_split(line, ' ');
	save_texture(img_dir, token, data->t_map, data);
}
