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
	if (data->press_s == 1)
		move_vertical(data, 's');
	if (data->press_a == 1)
		move_hozintal(data, 'a');
	if (data->press_d == 1)
		move_hozintal(data, 'd');
	if (data->press_left == 1)
		rotate_player(data, 'l');
	if (data->press_right == 1)
		rotate_player(data, 'r');
	if (data->press_w || data->press_s || data->press_a || data->press_d
		|| data->press_left || data->press_right)
		return (1);
	return (0);
}

void	move_vertical(t_data *data, char flag)
{
	double	temp_x;
	double	temp_y;
	int		dir;

	temp_x = data->p_x;
	temp_y = data->p_y;
	dir = 0;
	if (flag == 'w')
		dir = 1;
	else
		dir = -1;
	data->p_x += 0.05 * data->dir_x * dir;
	data->p_y += 0.05 * data->dir_y * dir;
	check_wall_hit(data, temp_x, temp_y);
}

void	move_hozintal(t_data *data, char flag)
{
	double	temp_x;
	double	temp_y;

	temp_x = data->p_x;
	temp_y = data->p_y;
	if (flag == 'a')
	{
		data->p_x += data->dir_y * 0.05;
		data->p_y += -data->dir_x * 0.05;
	}
	else if (flag == 'd')
	{
		data->p_x += -data->dir_y * 0.05;
		data->p_y += data->dir_x * 0.05;
	}
	check_wall_hit(data, temp_x, temp_y);
}

void	check_wall_hit(t_data *data, double temp_x, double temp_y)
{
	if (data->og_map[(int)data->p_y][(int)data->p_x] == '1')
	{
		data->p_y = temp_y;
		data->p_x = temp_x;
	}
}

void	rotate_player(t_data *data, char flag)
{
	double	angle;
	double	temp_x;
	double	temp_y;

	angle = 0.02;
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
