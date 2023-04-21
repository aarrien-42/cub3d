/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:53:07 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/21 20:42:29 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cont_token(char *argv)
{
	int		fd;
	char	*line;
	size_t	c_line;
	int		cont;
	int		i;

	cont = 0;
	fd = ft_open(argv);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		c_line = 0;
		i = -1;
		while (line[++i])
		{
			if (line[i] == '\t' || line[i] == '\n' || line[i] == '\v'\
				|| line[i] == '\f' || line[i] == '\r' || line[i] == ' ')
				c_line++;
		}
		printf("line_len: %zu ---- c_line: %zu\n", ft_strlen(line), c_line);
		if (ft_strlen(line) != c_line)
			cont ++;
	}
	printf("cont: %d\n", cont);
	if (cont > 6)
	{
		printf("Error: Archivo invalido\n");
		exit (-1);
	}
}

void	check_map(char *argv)
{
	cont_token(argv);
}