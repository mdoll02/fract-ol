/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:25 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/17 16:00:20 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"


int	main(void)
{
	t_mlx	*data;

	data = init_struct();
	mandelbrot(data);
	mlx_key_hook(data->win, process_k_input, data);
	mlx_hook(data->win, 17, 0, close, data);
	mlx_loop(data->mlx);
}

t_mlx	*init_struct(void)
{
	t_mlx	*data;


	data = (t_mlx *)malloc(sizeof(t_mlx));
	data->iterations = 50;
	data->x_width = 1920;
	data->x_width = 1080;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_width, data->y_height, \
																"Fract-ol");
	return (data);
}
