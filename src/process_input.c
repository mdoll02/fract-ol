/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:27 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/20 12:10:06 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	process_k_input(int keycode, t_mlx *data)
{
	if (keycode == 4)
	{
		printf("HELP ME! PLS!");
		return (0);
	}
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
