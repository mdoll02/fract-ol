/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:27 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/26 11:49:55 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	process_k_input(int keycode, t_mlx *data)
{
	if ((keycode >= 18 && keycode <= 21) || keycode == 23)
		change_color(keycode, data);
	if (keycode == 53)
		ft_close(data);
	if (keycode == 30)
	{
		data->iterations += 5;
		choose_set(data);
	}
	if (keycode == 44)
	{
		if (data->iterations >= 5)
		{
			data->iterations -= 5;
			choose_set(data);
		}
	}
	if (keycode == 15)
		reset_values(data);
	if (keycode >= 123 && keycode <= 126)
		ft_move(data, keycode);
	change_interface(data);
	return (0);
}

int	process_m_input(int keycode, int x, int y, t_mlx *data)
{
	if (keycode == 4)
	{
		zoom(data, x, y, -1);
	}
	else if (keycode == 5)
	{
		zoom(data, x, y, 1);
	}
	else if (keycode == 1)
	{
		data->k = (x / (double)data->x_width) * (y / (double)data->y_height);
	}
	choose_set(data);
	change_interface(data);
	return (0);
}

int	ft_close(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	free(data);
	exit(0);
}
