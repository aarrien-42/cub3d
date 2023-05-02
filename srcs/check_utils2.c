/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:53:30 by jdasilva          #+#    #+#             */
/*   Updated: 2023/05/02 17:34:23 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

int	check_texture(char *txt, char **dir, char *aux, int fd)
{
	split_free(dir);
	free(aux);
	if (!txt)
	{
		ft_close(fd);
		perror("Error");
		return (0);
	}
	return (1);
}

void	check_number(char **split_color, char token, t_data *data, int fd)
{
	int	numb[3];
	int	i;

	i = -1;
	while (++i < 3)
	{
		numb[i] = ft_atoi(split_color[i]);
		if (numb[i] > 255)
		{
			ft_close(fd);
			printf("Error: %c ---- Numero: %d > 255\n", token, numb[i]);
			ft_texture_free(data->t_map, 1);
		}
	}
}

void	cont_number(char **split_color, char token, t_data *data, int fd)
{
	int		i;
	size_t	size;

	i = -1;
	while (split_color[++i])
	{
		size = ft_strlen(split_color[i]);
		if (size > 3)
		{
			ft_close(fd);
			printf("Error: %c --- Numero: %s\n", token, split_color[i]);
			split_free(split_color);
			ft_texture_free(data->t_map, 1);
		}
	}
}

void	check_fin_color(char *line, int i, int fd, t_data *data)
{
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
		{
			ft_close(fd);
			printf("Error: Formato numerico erroneo\n");
			ft_texture_free(data->t_map, 1);
		}
		i ++;
	}
}

void	error_color(char token, int fd, t_data *data)
{
	ft_close(fd);
	printf("Error: Formato erroneo en %c", token);
	printf(" solo puede tener dos comas. Ejemplo:0,255,255\n");
	ft_texture_free(data->t_map, 1);
}
