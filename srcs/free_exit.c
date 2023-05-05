/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:37:33 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/04 16:10:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	ft_texture_free2(t_map *map)
{
	if (map->ea_img)
	{
		free(map->ea_img->img);
		if (map->ea_img->addr)
			free(map->ea_img->addr);
		free(map->ea_img);
	}
	if (map->we_img)
	{
		free(map->we_img->img);
		if (map->we_img->addr)
			free(map->we_img->addr);
		free(map->we_img);
	}
}

void	ft_texture_free(t_map *map, int flag)
{
	if (map->no_img)
	{
		free(map->no_img->img);
		if (map->no_img->addr)
			free(map->no_img->addr);
		free(map->no_img);
	}
	if (map->so_img)
	{
		free(map->so_img->img);
		if (map->so_img->addr)
			free(map->so_img->addr);
		free(map->so_img);
	}
	ft_texture_free2(map);
	free(map);
	if (flag == 1)
		exit(-1);
}
