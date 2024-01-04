/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:40:12 by ccosta-c          #+#    #+#             */
/*   Updated: 2024/01/04 16:36:52 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	parser(t_data *data)
{
	int	fd;

	fd = open(data->info->file_path, O_RDONLY);
	if (fd == -1)
		error_handler_checks(data, -1);
	get_tex_col(data, fd);
	close(fd);
}

void	get_tex_col(t_data *data, int fd)
{
	char	*line;
	int		error;

	error = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (error == 0)
			error = get_textures(data, line);
		if (error == 0)
			error = get_colors(data, line);
		free(line);
	}
	if (error != 0)
	{
		free(line);
		close(fd);
		error_handler_checks(data, error);
	}
	check_textures(data);
	check_colors(data);
}

int	get_textures(t_data *data, char *line)
{
	char	**pp;

	pp = ft_split(line, ' ');
	if (!pp[1])
		return (free_array(pp), 0);
	if (d_check_tex(data, pp) != 0)
		return (free_array(pp), -6);
	if (ft_strcmp("NO", pp[0]) == 0)
	{
		data->info->no_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strcmp("SO", pp[0]) == 0)
	{
		data->info->so_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strcmp("WE", pp[0]) == 0)
	{
		data->info->we_tex = ft_strtrim(pp[1], "\n");
	}
	if (ft_strcmp("EA", pp[0]) == 0)
	{
		data->info->ea_tex = ft_strtrim(pp[1], "\n");
	}
	return (free_array(pp), 0);
}

int	get_colors(t_data	*data, char *line)
{
	if (ft_strncmp("C ", line, 2) == 0 && data->info->ceiling_rgb == true)
		return (-9);
	if (ft_strncmp("F ", line, 2) == 0 && data->info->floor_rgb == true)
		return (-9);
	if (ft_strncmp("F ", line, 2) == 0 && data->info->floor_rgb == false)
	{
		return (get_colors_xtra(data, line, "F ", 'F'));
	}
	if (ft_strncmp("C ", line, 2) == 0 && data->info->ceiling_rgb == false)
	{
		return (get_colors_xtra(data, line, "C ", 'C'));
	}
	return (0);
}

int	get_colors_xtra(t_data *data, char *line, char *tile, char place)
{
	char	**rgb;
	char	*colors;

	colors = ft_strtrim(line, tile);
	if (colors[0] == '\0' || colors[0] == '\n')
		return (free(colors), -4);
	rgb = ft_split(colors, ',');
	free(colors);
	if (check_numeric(rgb) == -1)
		return (free_array(rgb), -7);
	convert_string_to_rgb(data, rgb, place);
	free_array(rgb);
	return (0);
}
