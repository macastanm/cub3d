/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:53:19 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 11:23:53 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	print_cub_info(t_data *data)
{
	printf(GRN"Retrieving textures information:\n"BLD);
	printf("North- %s\n", data->info->no_tex);
	printf("South- %s\n", data->info->so_tex);
	printf("West- %s\n", data->info->we_tex);
	printf("East- %s\n\n", data->info->ea_tex);
	printf(GRN"Retrieving colors information:\n"BLD);
	printf("\033[38;2;%i;%i;%im", data->info->floor_r,
		data->info->floor_g, data->info->floor_b);
	printf("Floor Color- (%i,%i,%i)\n", data->info->floor_r,
		data->info->floor_g, data->info->floor_b);
	printf("\033[38;2;%i;%i;%im", data->info->ceiling_r,
		data->info->ceiling_g, data->info->ceiling_b);
	printf("Ceiling Color- (%i,%i,%i)\n\n"BLD, data->info->ceiling_r,
		data->info->ceiling_g, data->info->ceiling_b);
	printf(GRN"Retrieving og_map information:\n"BLD);
	printf("Map Height: %i\n", data->map_height + 1);
	printf("Map Width: %i\n", data->map_width + 1);
	print_map(data, data->og_map, 2);
}

void	print_map(t_data *data, char **map, int size)
{
	int	i;

	i = 0;
	printf("Map Array:\n");
	line_print_map(data, size);
	while (map[i] != NULL)
	{
		printf(GRY"*"BLD);
		printf("%s", map[i]);
		printf(GRY"*"BLD);
		i++;
		printf("\n");
	}
	line_print_map(data, size);
	printf("" NRM);
}

void	line_print_map(t_data *data, int size)
{
	int	i;

	i = -1;
	while (++i <= data->map_width + size)
		printf(GRY"*");
	printf("\n"BLD);
}

void	print_all(t_data *data)
{
	static int	j;

	printf("\n%i vezes:\n", j);
	printf("px- %f\n", data->p_x);
	printf("py- %f\n", data->p_y);
	printf("dir_x- %f\n", data->dir_x);
	printf("dir_y- %f\n", data->dir_y);
	printf("plane_x- %f\n", data->plane_x);
	printf("plane_y- %f\n", data->plane_y);
	printf("camera_x- %lf\n", data->camera_x);
	printf("raydir_x- %lf\n", data->raydir_x);
	printf("raydir_y- %lf\n", data->raydir_y);
	printf("side_dist_x- %lf\n", data->side_dist_x);
	printf("side_dist_y- %lf\n", data->side_dist_y);
	printf("delta_dist_x- %lf\n", data->delta_dist_x);
	printf("delta_dist_y- %lf\n", data->delta_dist_y);
	printf("i: %i\n", data->i);
	printf("mapx: %i\n", data->mapx);
	printf("mapy: %i\n", data->mapy);
	printf("pwalldist- %lf\n", data->pwalldist);
	printf("stepx: %i\n", data->stepx);
	printf("stepy: %i\n", data->stepy);
	printf("hit: %i\n", data->hit);
	printf("side: %i\n", data->side);
	printf("draw_start: %i\n", data->draw_start);
	printf("draw_end: %i\n", data->draw_end);
	printf("lineheight: %i\n", data->lineheight);
	printf("wall_x- %lf\n", data->wall_x);
	printf("tex_x: %i\n", data->tex_x);
	printf("tex_y: %i\n", data->tex_y);
	printf("text_step- %lf\n", data->text_step);
	printf("text_pos- %lf\n", data->text_pos);
	j++;
}
