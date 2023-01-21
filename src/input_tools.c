/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:42:56 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/21 13:49:37 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	change_interface(t_mlx *data)
{
	char	*iterations_string;

	iterations_string = ft_itoa(data->iterations);
	mlx_string_put(data->mlx, data->win, data->x_width - 120, \
		15, 0x0000E8EC, iterations_string);
	free(iterations_string);
}

int	ft_close(t_mlx *data)
{

	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	free(data);
	write(2, "EXIT\n", 5);
	exit(0);
}

void	zoom(t_mlx *data, int x, int y, int direction)
{
	if (direction == 1)
	{
		data->max_re = (1 / 2.0) * data->max_re;
		data->max_im = (1 / 2.0) * data->max_im;
		data->min_re = (((double)x / data->x_width) * data->max_re) \
					- (data->max_re / 2) + (data->min_re);
		data->min_im = ((((-1) * ((double)y)) / data->y_height) * \
			data->max_im) + (data->max_im / 2) + (data->min_im);
	}
	else
		printf("ZOOM OUT: \t\tx = %d\ty = %d\n", x, y);
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
	if (keycode == 22)
		data->color_set = "bw";
	mandelbrot(data);
}
