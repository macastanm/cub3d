/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:35 by macastan          #+#    #+#             */
/*   Updated: 2023/12/18 17:42:38 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	init_texture_stuff(t_data *data)
{
	data->img->addr = NULL;
	data->img->height = 0;
	data->img->width = 0;
	data->img->bpp = 0;
	data->img->line_length = 0;
	data->img->endian = 0;
	data->no->addr = NULL;
	data->no->height = 0;
	data->no->width = 0;
	data->no->bpp = 0;
	data->no->line_length = 0;
	data->no->endian = 0;
	data->so->addr = NULL;
	data->so->height = 0;
	data->so->width = 0;
	data->so->bpp = 0;
	data->so->line_length = 0;
	data->so->endian = 0;
	data->sone->addr = NULL;
	data->sone->height = 0;
	data->sone->width = 0;
	data->sone->bpp = 0;
	data->sone->line_length = 0;
	data->sone->endian = 0;
	init_texture_stuff2(data);
}

void	init_ray_stuff(t_data *structure)
{
	structure->p_x = 0;
	structure->p_y = 0;
	structure->dir_x = 0;
	structure->dir_y = 0;
	structure->plane_x = 0;
	structure->plane_y = 0;
	structure->camera_x = 0;
	structure->raydir_x = 0;
	structure->raydir_y = 0;
	structure->side_dist_x = 0;
	structure->side_dist_y = 0;
	structure->delta_dist_x = 0;
	structure->delta_dist_y = 0;
	structure->i = 0;
	structure->mapx = 0;
	structure->mapy = 0;
	structure->pwalldist = 0;
	structure->stepx = 0;
	structure->stepy = 0;
	init_ray_stuff2(structure);
}

void	init_texture_stuff2(t_data *data)
{
	data->stwo->addr = NULL;
	data->stwo->height = 0;
	data->stwo->width = 0;
	data->stwo->bpp = 0;
	data->stwo->line_length = 0;
	data->stwo->endian = 0;
	data->sthree->addr = NULL;
	data->sthree->height = 0;
	data->sthree->width = 0;
	data->sthree->bpp = 0;
	data->sthree->line_length = 0;
	data->sthree->endian = 0;
	data->we->addr = NULL;
	data->we->height = 0;
	data->we->width = 0;
	data->we->bpp = 0;
	data->we->line_length = 0;
	data->we->endian = 0;
	data->ea->addr = NULL;
	data->ea->height = 0;
	data->ea->width = 0;
	data->ea->bpp = 0;
	data->ea->line_length = 0;
	data->ea->endian = 0;
	init_minimap_stuff(data);
}

void	init_ray_stuff2(t_data *structure)
{
	structure->hit = 0;
	structure->side = 0;
	structure->draw_start = 0;
	structure->draw_end = 0;
	structure->lineheight = 0;
	structure->wall_x = 0;
	structure->tex_x = 0;
	structure->tex_y = 0;
	structure->text_step = 0;
	structure->text_pos = 0;
	structure->press_a = 0;
	structure->press_d = 0;
	structure->press_w = 0;
	structure->press_s = 0;
	structure->press_right = 0;
	structure->press_left = 0;
}

void	open_addr(t_data *data)
{
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_length, &data->img->endian);
	data->no->addr = mlx_get_data_addr(data->no->img, &data->no->bpp,
			&data->no->line_length, &data->no->endian);
	data->so->addr = mlx_get_data_addr(data->so->img, &data->so->bpp,
			&data->so->line_length, &data->so->endian);
	data->we->addr = mlx_get_data_addr(data->we->img, &data->we->bpp,
			&data->we->line_length, &data->we->endian);
	data->ea->addr = mlx_get_data_addr(data->ea->img, &data->ea->bpp,
			&data->ea->line_length, &data->ea->endian);
	data->sone->addr = mlx_get_data_addr(data->sone->img, &data->sone->bpp,
			&data->sone->line_length, &data->sone->endian);
	data->stwo->addr = mlx_get_data_addr(data->stwo->img, &data->stwo->bpp,
			&data->stwo->line_length, &data->stwo->endian);
	data->sthree->addr = mlx_get_data_addr(data->sthree->img,
			&data->sthree->bpp, &data->sthree->line_length,
			&data->sthree->endian);
	data->eone->addr = mlx_get_data_addr(data->eone->img, &data->eone->bpp,
			&data->eone->line_length, &data->eone->endian);
	data->etwo->addr = mlx_get_data_addr(data->etwo->img, &data->etwo->bpp,
			&data->etwo->line_length, &data->etwo->endian);
	data->ethree->addr = mlx_get_data_addr(data->ethree->img,
			&data->ethree->bpp, &data->ethree->line_length,
			&data->ethree->endian);
}
