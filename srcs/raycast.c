/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarrien- <aarrien-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:31 by aarrien-          #+#    #+#             */
/*   Updated: 2023/04/24 15:21:27 by aarrien-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/cub3d.h"

double	raycast(double rayDirX, double rayDirY, double posX, double posY)
{
	/*int worldMap[24][24]= \
	{
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};*/
	int worldMap[6][11]= \
	{
	  {1,2,1,2,1,2,1,2,1,2,1},
	  {2,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,1},
	  {2,0,0,-1,0,0,0,0,0,0,2},
	  {1,0,0,0,0,0,0,0,0,0,2},
	  {1,1,1,1,2,1,2,1,2,1,1}
	};
	int		mapX;
	int		mapY;
	double	deltaDistX;
	double	deltaDistY;
	double	sideDistX;
	double	sideDistY;
	int		stepX;
	int		stepY;
	double	dist;

	//deltaDistX = fabs(1 / rayDirX);
	//deltaDistY = fabs(1 / rayDirY);
	//deltaDistX = sqrt(1 + pow(rayDirY / rayDirX, 2));
	//deltaDistY = sqrt(1 + pow(rayDirX / rayDirY, 2));

	// Posición en mapa y distancia entre colisiones
	mapX = (int)posX;
	mapY = (int)posY;
	if (rayDirX == 0)
		deltaDistX = 1e30;
	else
		deltaDistX = fabs(1 / rayDirX);
	if (rayDirY == 0)
		deltaDistY = 1e30;
	else
		deltaDistY = fabs(1 / rayDirY);

	//Calcular step y sideDist
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (posX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - posX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (posY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - posY) * deltaDistY;
	}

	printf("\n	sideDist (%f, %f), deltaDist (%f, %f)\n", sideDistX, sideDistY, deltaDistX, deltaDistY);
	//DDA
	while (1)
	{
		if (worldMap[mapY][mapX] > 0)
			break;
		if(sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
		}
	}
	if (worldMap[mapY][mapX] == 1)
		color = encode_rgb(255, 0, 200);
	else
		color = encode_rgb(255, 0, 0);
	// Distance
	if (sideDistX < sideDistY)
		dist = sideDistX;
	else
		dist = sideDistY;
	printf("wall hit in ray (%f, %f) in map pos (%d, %d) dist => %f\n", rayDirX, rayDirY, mapY, mapX, dist);
	return (dist);
}