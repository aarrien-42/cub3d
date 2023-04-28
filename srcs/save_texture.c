/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:42:25 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/28 18:48:25 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture2(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	if (!ft_strncmp(dir[0], "WE", 2))
	{
		data->t_map->WE_img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
		if (!check_texture(data->t_map->WE_img, dir, aux, fd))
			ft_texture_free(data->t_map, 1);
	}
	else if (!ft_strncmp(dir[0], "EA", 2))
	{
		data->t_map->EA_img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
		if (!check_texture(data->t_map->EA_img, dir, aux, fd))
			ft_texture_free(data->t_map, 1);
	}
}

void	get_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	if (!ft_strncmp(dir[0], "NO", 2))
	{
		data->t_map->NO_img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
		if (!check_texture(data->t_map->NO_img, dir, aux, fd))
			ft_texture_free(data->t_map, 1);
	}
	else if (!ft_strncmp(dir[0], "SO", 2))
	{
		data->t_map->SO_img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
		if (!check_texture(data->t_map->SO_img, dir, aux, fd))
			ft_texture_free(data->t_map, 1);
	}
	else
		get_texture2(dir, aux, data, fd);
}

void	open_check_ext(char *texture, char *token, t_map *map, int fd)
{
	open_texture(texture, token, map, fd);
	if (!img_ext(texture, ".xpm", token, fd))
		ft_texture_free(map, 1);
}

void	save_texture(char **dir, char *token, t_data *data, int fd)
{
	char	*aux;
	char	*strim;

	if (dir[1][ft_strlen(dir[1]) - 1] == '\n')
		aux = ft_substr(dir[1], 0, ft_strlen(dir[1]) - 1);
	else
	{
		strim = ft_strtrim(dir[1], " ");
		aux = ft_substr(strim, 0, ft_strlen(strim));
		free(strim);
	}	
	open_check_ext(aux, token, data->t_map, fd);
	get_texture(dir, aux, data, fd);
}

void	get_image(char *line, char *token, t_data *data, int fd)
{
	char	**dir;

	dir = ft_split(line, ' ');
	if (ft_strlen(dir[1]) == 1)
	{
		ft_close(fd);
		printf("Error: %s No hay direccion de textura\n", token);
		exit (-1);
	}
	save_texture(dir, token, data, fd);
}
