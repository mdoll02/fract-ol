/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:25 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/24 11:12:49 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*data;

	if (check_parameters(argc, argv) == -1)
		return (-1);
	data = init_struct(argc, argv);
	if (data->fractal == 0)
		mandelbrot(data);
	// else if (data->fractal == 1)
	// 	julia(data);
	change_interface(data);
	mlx_key_hook(data->win, process_k_input, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_mouse_hook(data->win, process_m_input, data);
	mlx_loop(data->mlx);
}
