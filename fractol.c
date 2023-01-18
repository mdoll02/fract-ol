/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:25 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/18 10:47:36 by mdoll            ###   ########.fr       */
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
