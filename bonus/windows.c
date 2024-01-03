/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:36:07 by ccosta-c          #+#    #+#             */
/*   Updated: 2024/01/03 17:00:12 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	start_windows(t_data *data)
{
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	init_minimap(data);
	draw_raycast(data);
	mlx_hook(data->win, KeyPress, KeyPressMask, ft_press_key, data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, ft_release_key, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, &free_exit, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
}

void	draw_raycast(t_data *data)
{
	put_ceiling_floor(data);
	data->i = 0;
	data->sprite++;
	while (data->i < WIDTH)
	{
		ray_calculations(data);
		get_step_sidedist(data);
		get_hit(data);
		get_wall_h(data);
		get_tex_wall(data);
		draw_wall(data, data->i);
		data->i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->mini->mini->img, 0, 0);
}

int	game_loop(t_data *data)
{
	ft_movements(data);
	mlx_destroy_image(data->mlx, data->mini->mini->img);
	data->mini->mini->img = mlx_new_image(data->mlx,
			data->mini->width, data->mini->height);
	data->mini->x = 0;
	data->mini->y = 0;
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	draw_raycast(data);
	return (0);
}
