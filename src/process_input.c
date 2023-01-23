/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:27 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/23 14:43:21 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	process_k_input(int keycode, t_mlx *data)
{
	if ((keycode >= 18 && keycode <= 21) || keycode == 23)
		change_color(keycode, data);
	if (keycode == 53)
	{
		ft_close(data);
	}
	if (keycode == 30)
	{
		data->iterations += 5;
		mandelbrot(data);
		change_interface(data);
	}
	if (keycode == 44)
	{
		if (data->iterations >= 5)
		{
			data->iterations -= 5;
			mandelbrot(data);
			change_interface(data);
		}
	}
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
	mandelbrot(data);
	change_interface(data);
	return (0);
}
