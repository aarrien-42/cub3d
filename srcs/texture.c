/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:08:15 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/02 18:01:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_no_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->no_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->no_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->no_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->no_img->addr = mlx_get_data_addr(data->t_map->no_img->img, \
		&data->t_map->no_img->bpp, &data->t_map->no_img->size, \
			&data->t_map->no_img->endian);
}

void	ft_so_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->so_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->so_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->so_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->so_img->addr = mlx_get_data_addr(data->t_map->so_img->img, \
		&data->t_map->so_img->bpp, &data->t_map->so_img->size, \
			&data->t_map->so_img->endian);
}

void	ft_we_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->we_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->we_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->we_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->we_img->addr = mlx_get_data_addr(data->t_map->we_img->img, \
		&data->t_map->we_img->bpp, &data->t_map->we_img->size, \
		&data->t_map->we_img->endian);
}

void	ft_ea_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->ea_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->ea_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->ea_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->ea_img->addr = mlx_get_data_addr(data->t_map->ea_img->img, \
		&data->t_map->ea_img->bpp, &data->t_map->ea_img->size, \
		&data->t_map->ea_img->endian);
}
