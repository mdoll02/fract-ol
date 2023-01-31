/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:42:56 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/31 11:35:59 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	change_interface(t_mlx *data)
{
	char	*iterations_string;

	iterations_string = ft_itoa(data->iterations);
	mlx_string_put(data->mlx, data->win, data->x_width - 72, \
		16, 0x0000E8EC, iterations_string);
	mlx_string_put(data->mlx, data->win, data->x_width - 150, \
		15, 0x0000E8EC, "Iterations:");
	free(iterations_string);
}

void	reset_values(t_mlx *data)
{
	data->min_re = data->tmp_array[0];
	data->max_re = data->tmp_array[1];
	data->min_im = data->tmp_array[2];
	data->max_im = data->tmp_array[3];
	if (data->fractal == 1)
		data->k = data->tmp_array[4];
	choose_set(data);
}

void	zoom(t_mlx *data, int x, int y, int direction)
{
	double	dx;
	double	dy;
	double	zoom_f;

	zoom_f = 0.3;
	dx = (data->max_re - data->min_re) / data->x_width;
	dy = (data->max_im - data->min_im) / data->y_height;
	if (direction == 1)
	{
		data->min_re = (data->min_re + ((dx * x) * zoom_f));
		data->max_re = (data->max_re - ((dx * (data->x_width - x) * zoom_f)));
		data->max_im = (data->max_im - ((dy * y) * zoom_f));
		data->min_im = (data->min_im + ((dy * (data->y_height - y) * zoom_f)));
	}
	else
	{
		data->min_re = (data->min_re - ((dx * x) * zoom_f));
		data->max_re = (data->max_re + ((dx * (data->x_width - x) * zoom_f)));
		data->max_im = (data->max_im + ((dy * y) * zoom_f));
		data->min_im = (data->min_im - ((dy * (data->y_height - y) * zoom_f)));
	}
}

void	change_color(int keycode, t_mlx *data)
{
	if (keycode == 18)
		data->color_set = "red";
	if (keycode == 19)
		data->color_set = "green";
	if (keycode == 20)
		data->color_set = "blue";
	if (keycode == 21)
		data->color_set = "idk";
	if (keycode == 23)
		data->color_set = "bw";
	choose_set(data);
	change_interface(data);
}

void	choose_set(t_mlx *data)
{
	if (data->fractal == 0)
		mandelbrot(data);
	if (data->fractal == 1)
		julia(data);
	if (data->fractal == 2)
		burning_ship(data);
}
