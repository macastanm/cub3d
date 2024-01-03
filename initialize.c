/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:23:46 by ccosta-c          #+#    #+#             */
/*   Updated: 2024/01/02 14:35:37 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

t_data	*initialize_struct(char *path)
{
	t_data	*structure;

	structure = malloc((sizeof (t_data)));
	structure->info = initialize_tinfo(path);
	structure->img = malloc(sizeof (t_textures));
	structure->no = malloc(sizeof (t_textures));
	structure->so = malloc(sizeof (t_textures));
	structure->we = malloc(sizeof (t_textures));
	structure->ea = malloc(sizeof (t_textures));
	structure->map_height = 0;
	structure->map_width = 0;
	structure->map_found = false;
	structure->win = NULL;
	structure->mlx = NULL;
	structure->no->img = NULL;
	structure->so->img = NULL;
	structure->ea->img = NULL;
	structure->we->img = NULL;
	init_texture_stuff(structure);
	structure->og_map = NULL;
	structure->map = NULL;
	init_ray_stuff(structure);
	return (structure);
}

void	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	open_images(data);
	open_addr(data);
}

void	open_images(t_data *data)
{
	data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->no->img = mlx_xpm_file_to_image(data->mlx, data->info->no_tex,
			&data->no->width, &data->no->height);
	data->so->img = mlx_xpm_file_to_image(data->mlx, data->info->so_tex,
			&data->so->width, &data->so->height);
	data->ea->img = mlx_xpm_file_to_image(data->mlx, data->info->ea_tex,
			&data->ea->width, &data->ea->height);
	data->we->img = mlx_xpm_file_to_image(data->mlx, data->info->we_tex,
			&data->we->width, &data->we->height);
	if ((data->no->img == NULL) || (data->so->img == NULL)
		|| (data->ea->img == NULL) || (data->we->img == NULL))
		error_handler_checks(data, -6);
}

t_info	*initialize_tinfo(char *path)
{
	t_info	*structure;

	structure = malloc(sizeof (t_info));
	structure->file_path = ft_strdup(path);
	structure->floor_r = 0;
	structure->floor_g = 0;
	structure->floor_b = 0;
	structure->ceiling_r = 0;
	structure->ceiling_g = 0;
	structure->ceiling_b = 0;
	structure->c_color = 0;
	structure->f_color = 0;
	structure->floor_rgb = false;
	structure->ceiling_rgb = false;
	structure->no_tex = NULL;
	structure->so_tex = NULL;
	structure->ea_tex = NULL;
	structure->we_tex = NULL;
	return (structure);
}
