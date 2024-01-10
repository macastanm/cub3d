/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dinamic_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:48:24 by macastan          #+#    #+#             */
/*   Updated: 2024/01/03 12:48:26 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	draw_dinamic_map(t_data *data, int x, int y)
{
	int	tempx;
	int	tempy;

	y = (int)data->p_y - 5;
	tempy = y;
	while (y < (tempy + 11))
	{
		x = (int)data->p_x - 5;
		tempx = x;
		while (x < (tempx + 11))
		{
			if (y >= data->map_height || y < 0 || x < 0
				|| x >= (data->map_width + 1))
				draw_pixel(data, VOID_COLOR);
			else if (ft_strchr("1", data->og_map[y][x]))
				draw_pixel(data, WALL_COLOR);
			else if (ft_strchr("0NSEW", data->og_map[y][x]))
				draw_pixel(data, data->info->f_color);
			x++;
			data->mini->x += 13;
		}
		data->mini->y += 13;
		data->mini->x = 0;
		y++;
	}
}

void	draw_static_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			my_mlx_pixel_put_mini(data, ((13 * 5) + j),
				((13 * 5) + i), PLAYER_COLOR);
			j++;
		}
		i++;
	}
}
