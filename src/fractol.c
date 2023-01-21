/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:25 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/21 13:42:03 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	*data;

	if (argc > 3)
	{
		write(1, "Enter a width\n", 14);
		return (1);
	}
	data = init_struct(argv, argc);
	mandelbrot(data);
	change_interface(data);
	mlx_key_hook(data->win, process_k_input, data);
	mlx_hook(data->win, 17, 0, close, data);
	mlx_mouse_hook(data->win, process_m_input, data);
	mlx_loop(data->mlx);
}
