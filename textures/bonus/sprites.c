/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:42:57 by macastan          #+#    #+#             */
/*   Updated: 2024/01/04 12:42:59 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

void	init_sprite(t_data *data)
{
	data->eone->addr = NULL;
	data->eone->height = 0;
	data->eone->width = 0;
	data->eone->bpp = 0;
	data->eone->line_length = 0;
	data->eone->endian = 0;
	data->etwo->addr = NULL;
	data->etwo->height = 0;
	data->etwo->width = 0;
	data->etwo->bpp = 0;
	data->etwo->line_length = 0;
	data->etwo->endian = 0;
	data->ethree->addr = NULL;
	data->ethree->height = 0;
	data->ethree->width = 0;
	data->ethree->bpp = 0;
	data->ethree->line_length = 0;
	data->ethree->endian = 0;
}

t_textures	*change_sprite2(t_data *data)
{
	if (data->sprite >= 30)
		data->sprite = 0;
	if (data->sprite >= 0 && data->sprite < 10)
	{
		if (data->eone == NULL)
			return (data->ea);
		else
			return (data->eone);
	}
	else if (data->sprite >= 10 && data->sprite < 20)
	{
		if (data->etwo == NULL)
			return (data->ea);
		else
			return (data->etwo);
	}
	else if (data->sprite >= 20 && data->sprite < 30)
	{
		if (data->ethree == NULL)
			return (data->ea);
		else
			return (data->ethree);
	}
	return (data->ea);
}
