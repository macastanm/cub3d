/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_static_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:48:11 by macastan          #+#    #+#             */
/*   Updated: 2024/01/03 12:48:13 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	draw_static_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < (data->map_width + 1))
		{
			if (ft_strchr("1", data->og_map[y][x]))
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

void	draw_dinamic_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			my_mlx_pixel_put_mini(data, (data->mini->p_x + j),
				(data->mini->p_y + i), PLAYER_COLOR);
			j++;
		}
		i++;
	}
}
