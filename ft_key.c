/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:17:46 by macastan          #+#    #+#             */
/*   Updated: 2023/12/20 17:17:49 by macastan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lib_bonus.h"

int	ft_press_key(int keysym, t_data *data)
{
	if (keysym == 65307)
		free_exit(data);
	if (keysym == 119)
		data->press_w = 1;
	if (keysym == 115)
		data->press_s = 1;
	if (keysym == 97)
		data->press_a = 1;
	if (keysym == 100)
		data->press_d = 1;
	if (keysym == 65361)
		data->press_left = 1;
	if (keysym == 65363)
		data->press_right = 1;
	return (0);
}

int	ft_release_key(int keysym, t_data *data)
{
	if (keysym == 119)
		data->press_w = 0;
	if (keysym == 115)
		data->press_s = 0;
	if (keysym == 97)
		data->press_a = 0;
	if (keysym == 100)
		data->press_d = 0;
	if (keysym == 65361)
		data->press_left = 0;
	if (keysym == 65363)
		data->press_right = 0;
	return (0);
}
