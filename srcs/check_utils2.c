/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:53:30 by jdasilva          #+#    #+#             */
/*   Updated: 2023/04/26 18:53:52 by jdasilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
