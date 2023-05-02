/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:08:15 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/02 17:28:43 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_no_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->NO_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->NO_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->NO_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->NO_img->addr = mlx_get_data_addr(data->t_map->NO_img->img, \
		&data->t_map->NO_img->bpp, &data->t_map->NO_img->size, \
			&data->t_map->NO_img->endian);
}

void	ft_so_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->SO_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->SO_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->SO_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->SO_img->addr = mlx_get_data_addr(data->t_map->SO_img->img, \
		&data->t_map->SO_img->bpp, &data->t_map->NO_img->size, \
			&data->t_map->SO_img->endian);
}

void	ft_we_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->WE_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->WE_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->WE_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->WE_img->addr = mlx_get_data_addr(data->t_map->WE_img->img, \
		&data->t_map->WE_img->bpp, &data->t_map->WE_img->size, \
		&data->t_map->WE_img->endian);
}

void	ft_ea_texture(char **dir, char *aux, t_data *data, int fd)
{
	int		w;
	int		h;

	data->t_map->EA_img = (t_texture *)malloc(sizeof(t_texture));
	data->t_map->EA_img->img = mlx_xpm_file_to_image(data->mlx, aux, &w, &h);
	if (!check_texture(data->t_map->EA_img->img, dir, aux, fd))
		ft_texture_free(data->t_map, 1);
	data->t_map->EA_img->addr = mlx_get_data_addr(data->t_map->EA_img->img, \
		&data->t_map->EA_img->bpp, &data->t_map->EA_img->size, \
		&data->t_map->EA_img->endian);
}
