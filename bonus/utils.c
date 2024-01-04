/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:54:43 by ccosta-c          #+#    #+#             */
/*   Updated: 2024/01/04 14:55:03 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	convert_string_to_rgb(t_data *data, char **rgb, char place)
{
	if (place == 'F')
	{
		data->info->floor_r = ft_atoi(rgb[0]);
		data->info->floor_g = ft_atoi(rgb[1]);
		data->info->floor_b = ft_atoi(rgb[2]);
		data->info->floor_rgb = true;
	}
	if (place == 'C')
	{
		data->info->ceiling_r = ft_atoi(rgb[0]);
		data->info->ceiling_g = ft_atoi(rgb[1]);
		data->info->ceiling_b = ft_atoi(rgb[2]);
		data->info->ceiling_rgb = true;
	}
}

int	d_check_tex(t_data *data, char **pp)
{
	if (ft_strncmp(pp[0], "NO ", 3) != 0 && data->info->no_tex != NULL)
		return (1);
	if (ft_strncmp(pp[0], "SO ", 3) != 0 && data->info->so_tex != NULL)
		return (1);
	if (ft_strncmp(pp[0], "WE ", 3) != 0 && data->info->we_tex != NULL)
		return (1);
	if (ft_strncmp(pp[0], "EA ", 3) != 0 && data->info->ea_tex != NULL)
		return (1);
	return (0);
}
