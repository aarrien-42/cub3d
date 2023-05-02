/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:42:25 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/02 17:31:00 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	get_texture(char **dir, char *aux, t_data *data, int fd)
{
	if (!ft_strncmp(dir[0], "NO", 2))
		ft_no_texture(dir, aux, data, fd);
	else if (!ft_strncmp(dir[0], "SO", 2))
		ft_so_texture(dir, aux, data, fd);
	else if (!ft_strncmp(dir[0], "WE", 2))
		ft_we_texture(dir, aux, data, fd);
	else if (!ft_strncmp(dir[0], "EA", 2))
		ft_ea_texture(dir, aux, data, fd);
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
	free(line);
	if (ft_strlen(dir[1]) == 1)
	{
		ft_close(fd);
		printf("Error: %s No hay direccion de textura\n", token);
		exit (-1);
	}
	save_texture(dir, token, data, fd);
}
