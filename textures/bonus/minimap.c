/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:53:13 by macastan          #+#    #+#             */
/*   Updated: 2024/01/03 11:53:14 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	draw_minimap(t_data *data)
{
	data->mini->p_y = ((int) data->p_y) * 13;
	data->mini->p_x = ((int) data->p_x) * 13;
	if (data->mini->flag == 0)
	{
		draw_static_map(data);
		draw_dinamic_player(data);
	}
	if (data->mini->flag == 1)
	{
		draw_dinamic_map(data, 0, 0);
		draw_static_player(data);
	}
}

void	my_mlx_pixel_put_mini(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mini->mini->addr + (y * data->mini->mini->line_length + x
			* (data->mini->mini->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 13)
	{
		j = 0;
		while (j < 13)
		{
			my_mlx_pixel_put_mini(data, (data->mini->x + j),
				(data->mini->y + i), color);
			j++;
		}
		i++;
	}
}
