/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:37:33 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/02 17:35:58 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

void	ft_texture_free(t_map *map, int flag)
{
	if (map->NO_img)
	{
		free(map->NO_img->img);
		free(map->NO_img);
	}
	if (map->SO_img)
	{
		free(map->SO_img->img);
		free(map->SO_img);
	}
	if (map->EA_img)
	{
		free(map->EA_img->img);
		free(map->EA_img);
	}
	if (map->WE_img)
	{
		free(map->WE_img->img);
		free(map->WE_img);
	}
	free(map);
	if (flag == 1)
		exit(-1);
}
