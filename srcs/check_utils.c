/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:24:21 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/26 18:59:00 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_open(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror("Error open");
		exit(-1);
	}
	return (fd);
}

int	ft_close(int fd)
{
	close(fd);
	if (fd == -1)
	{
		perror("Error close");
		exit(-1);
	}
	return (fd);
}

void	split_free(char **str)
{
	int i;

	i = -1;
	if(str)
	{
		while(str[++i])
		{
			if(str[i])
				free(str[i]);
		}
		free(str);
	}
}

void	open_texture(char *img_dir, char *token, t_map *map, int fd2)
{
	int	fd;

	fd = open (img_dir, O_RDONLY);
	if (fd == -1)
	{
		ft_close(fd);
		ft_close(fd2);
		printf("char: %s\n", img_dir);
		printf("Error: Direccion de la textura %s es erronea\n", token);
		ft_texture_free(map, 1);
	}
	ft_close(fd);
}

int	img_ext(char *img, char *ext, char *token, int fd)
{
	int	len;

	len = ft_strlen(img) - 4;
	if (len < 0)
		len = 0;
	while (*(img + len) && *ext)
	{
		if (*(img + len) != *ext)
		{
			ft_close(fd);
			printf ("Error: La textura %s no es .xpm\n", token);
			return(0);
		}
		len++;
		ext++;
	}
	return(1);
}
