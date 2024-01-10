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
		if (data->eone->img == NULL)
			return (data->ea);
		else
			return (data->eone);
	}
	else if (data->sprite >= 10 && data->sprite < 20)
	{
		if (data->etwo->img == NULL)
			return (data->ea);
		else
			return (data->etwo);
	}
	else if (data->sprite >= 20 && data->sprite < 30)
	{
		if (data->ethree->img == NULL)
			return (data->ea);
		else
			return (data->ethree);
	}
	return (data->ea);
}

void	open_sprites_addr(t_data *data)
{
	if (data->sone->img)
		data->sone->addr = mlx_get_data_addr(data->sone->img, &data->sone->bpp, &data->sone->line_length, &data->sone->endian);
	if (data->stwo->img)
		data->stwo->addr = mlx_get_data_addr(data->stwo->img, &data->stwo->bpp, &data->stwo->line_length, &data->stwo->endian);
	if (data->sthree->img)
		data->sthree->addr = mlx_get_data_addr(data->sthree->img, &data->sthree->bpp, &data->sthree->line_length, &data->sthree->endian);
	if (data->eone->img)
		data->eone->addr = mlx_get_data_addr(data->eone->img, &data->eone->bpp, &data->eone->line_length, &data->eone->endian);
	if (data->etwo->img)
		data->etwo->addr = mlx_get_data_addr(data->etwo->img, &data->etwo->bpp, &data->etwo->line_length, &data->etwo->endian);
	if (data->ethree->img)
		data->ethree->addr = mlx_get_data_addr(data->ethree->img, &data->ethree->bpp, &data->ethree->line_length, &data->ethree->endian);
}

void	free_sprites2(t_data *data)
{
	if (data->sone->img)
		mlx_destroy_image(data->mlx, data->sone->img);
	if (data->stwo->img)
		mlx_destroy_image(data->mlx, data->stwo->img);
	if (data->sthree->img)
		mlx_destroy_image(data->mlx, data->sthree->img);
	if (data->eone->img)
		mlx_destroy_image(data->mlx, data->eone->img);
	if (data->etwo->img)
		mlx_destroy_image(data->mlx, data->etwo->img);
	if (data->ethree->img)
		mlx_destroy_image(data->mlx, data->ethree->img);
}
