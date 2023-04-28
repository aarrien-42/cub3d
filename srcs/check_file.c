/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:20:46 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/28 21:06:42 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_extension(const char *argv, const char *ext)
{
	int	len;

	if (!argv)
	{
		printf ("Error: No has seleccionado un archivo\n");
		exit (-1);
	}
	len = ft_strlen(argv) - 4;
	if (len < 0)
		len = 0;
	while (*(argv + len) && *ext)
	{
		if (*(argv + len) != *ext)
		{
			printf ("Error: El archivo no es .cub\n");
			exit (-1);
		}
		len++;
		ext++;
	}
}

int	repeated_or_null(int *cont, char *token)
{	
	if (*cont != 1)
	{
		if (*cont == 0)
			printf("Error: El indentificador %s no encontrado\n", token);
		else
			printf("Error: El identificador %s se repite\n", token);
		return (1);
	}
	return (0);
}

int	token(char *argv, char *token)
{
	int		fd;
	char	*line;
	int		cont;

	cont = 0;
	fd = ft_open(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, token, ft_strlen(token)))
		{
			if (line[ft_strlen(token)] != ' ')
				return (free(line), \
					printf("Error: %s no tiene espacio\n", token), 0);
			cont ++;
		}
		free(line);
	}
	if (repeated_or_null(&cont, token))
		return (free(line), ft_close(fd), 0);
	return (free(line), ft_close(fd), 1);
}

void	check_token(char *argv)
{
	if (!token(argv, "NO"))
		exit(-1);
	if (!token(argv, "SO"))
		exit(-1);
	if (!token(argv, "WE"))
		exit(-1);
	if (!token(argv, "EA"))
		exit(-1);
	if (!token(argv, "F"))
		exit(-1);
	if (!token(argv, "C"))
		exit(-1);
}

int	check_file(char *argv, t_data *data)
{
	check_extension(argv, ".cub");
	check_token(argv);
	check_map(argv, data);
	printf("todo perfecto\n");
	return (0);
}
