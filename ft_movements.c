/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:27:13 by macastan          #+#    #+#             */
/*   Updated: 2023/12/20 17:27:14 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

int	ft_movements(t_data *data)
{
	if (data->press_w == 1)
		move_vertical(data, 'w');
	else if (data->press_s == 1)
		move_vertical(data, 's');
	else if (data->press_a == 1)
		move_hozintal(data, 'a');
	else if (data->press_s == 1)
		move_hozintal(data, 's');
	else if (data->press_left == 1)
		rotate_player(data, 'l');
	else if (data->press_right == 1)
		rotate_player(data, 'r');
	else
		return (1);
	return (0);
}

void	move_vertical(t_data *data, char flag)
{
	if (flag == 'w')
	{
		if (data->og_map[(int)(data->p_y + data->dir_y * 0.2)][(int)data->p_x] != '1')
			data->p_y += data->dir_y * 0.2;
		if (data->og_map[(int)data->p_y][(int)(data->p_x + data->dir_x * 0.2)] != '1')
			data->p_x += data->dir_x * 0.2;
	}
	else if (flag == 's')
	{
		if (data->og_map[(int)(data->p_y + data->dir_y * 0.2)][(int)data->p_x] != '1')
			data->p_y -= data->dir_y * 0.2;
		if (data->og_map[(int)data->p_y][(int)(data->p_x + data->dir_x * 0.2)] != '1')
			data->p_x -= data->dir_x * 0.2;
	}
}

void	move_hozintal(t_data *data, char flag)
{
	if (flag == 'a')
	{
		if (data->og_map[(int) (data->p_y + data->dir_y * 0.2)][(int) data->p_x] != '1')
			data->p_y += data->dir_x * 0.2;
		if (data->og_map[(int) data->p_y][(int) (data->p_x + data->dir_x * 0.2)] != '1')
			data->p_x -= data->dir_y * 0.2;
	}
	else if (flag == 'd')
	{
		if (data->og_map[(int) (data->p_y + data->dir_y * 0.2)][(int) data->p_x] != '1')
			data->p_y -= data->dir_x * 0.2;
		if (data->og_map[(int) data->p_y][(int) (data->p_x + data->dir_x * 0.2)] != '1')
			data->p_x += data->dir_y * 0.2;
	}
}

void	rotate_player(t_data *data, char flag)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.10;
	if (flag != 'r')
		angle *= -1;
	temp_x = data->dir_x * cos(angle) - data->dir_y * sin(angle);
	temp_y = data->dir_x * sin(angle) + data->dir_y * cos(angle);
	data->dir_x = temp_x;
	data->dir_y = temp_y;
	temp_x = data->plane_x * cos(angle) - data->plane_y * sin(angle);
	temp_y = data->plane_x * sin(angle) + data->plane_y * cos(angle);
	data->plane_x = temp_x;
	data->plane_y = temp_y;
}