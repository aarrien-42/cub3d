/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:24:21 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/21 19:23:10 by jdasilva         ###   ########.fr       */
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
