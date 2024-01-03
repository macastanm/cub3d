/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccosta-c <ccosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:37:30 by ccosta-c          #+#    #+#             */
/*   Updated: 2023/11/23 11:22:16 by ccosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib.h"

void	get_map(t_data *data)
{
	get_size(data);
	get_map_array(data);
}

void	get_map_array(t_data *data)
{
	char	*line;
	int		fd;
	int		j;

	j = 0;
	fd = open(data->info->file_path, O_RDONLY);
	data->og_map = malloc(sizeof (char *) * (data->map_height + 1));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (data->map_found == 0)
			check_line(data, line);
		if (data->map_found == 1)
		{
			write_line(data, data->og_map, line, j);
			j++;
		}
		free(line);
	}
	data->og_map[j] = NULL;
}

void	write_line(t_data *data, char **map, char *line, int j)
{
	int		i;
	int		l;
	char	*new_line;

	i = 0;
	l = 0;
	new_line = ft_strtrim(line, "\n");
	map[j] = malloc(sizeof (char) * data->map_width + 2);
	while (new_line[i] && i <= data->map_width)
	{
		map[j][l++] = new_line[i++];
	}
	fill_line(map[j], l, data->map_width);
	free(new_line);
}

void	fill_line(char *array_line, int l, int map_width)
{
	while (l <= map_width)
	{
		array_line[l] = ' ';
		l++;
	}
	array_line[l] = '\0';
}
