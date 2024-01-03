/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:05:56 by macastan          #+#    #+#             */
/*   Updated: 2024/01/03 12:06:00 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	init_minimap_stuff(t_data *data)
{
	data->mini->mini = malloc(sizeof (t_textures));
	data->mini->mini->addr = NULL;
	data->mini->mini->height = 0;
	data->mini->mini->width = 0;
	data->mini->mini->bpp = 0;
	data->mini->mini->line_length = 0;
	data->mini->mini->endian = 0;
	data->mini->height = 0;
	data->mini->width = 0;
	data->mini->x = 0;
	data->mini->y = 0;
	data->mini->p_x = 0;
	data->mini->p_y = 0;
	data->mini->flag = 0;
}

int	check_map_height(t_data *data)
{
	if ((data->map_height * 13) <= 143)
		return (data->map_height * 13);
	else
		return (data->mini->flag = 1, 143);
}

int	check_map_width(t_data *data)
{
	if ((data->map_width * 13) <= 143)
		return ((data->map_width + 1) * 13);
	else
		return (data->mini->flag = 1, 143);
}

void	init_minimap(t_data *data)
{
	data->mini->height = check_map_height(data);
	data->mini->width = check_map_width(data);
	data->mini->mini->img = mlx_new_image(data->mlx, data->mini->width,
			data->mini->height);
	data->mini->mini->addr = mlx_get_data_addr(data->mini->mini->img,
			&data->mini->mini->bpp, &data->mini->mini->line_length,
			&data->mini->mini->endian);
	data->mini->x = 0;
	data->mini->y = 0;
}
