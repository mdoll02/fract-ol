/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/24 14:02:38 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mlx	*init_struct(int argc, char **argv)
{
	t_mlx	*data;

	data = (t_mlx *)malloc(sizeof(t_mlx));
	if (!data)
		exit(0);
	data->iterations = 51;
	data->x_width = ft_atoi(argv[3]);
	data->y_height = data->x_width / 1.7777;
	data = image_init(data);
	data->color_set = argv[2];
	data->std_col = 0x00000000;
	if (ft_strncmp(argv[1], "mandelbrot", 20) == 0)
	{
		data->fractal = 0;
		set_mandel_params(data);
	}
	if (ft_strncmp(argv[1], "julia", 20) == 0)
	{
		data->fractal = 1;
		set_julia_params(data);
		if (argc == 5)
			data->k = (double)ft_atoi(argv[4]) * 0.0123456789;
		else
			data->k = 0.4042832;
	}
	return (data);
}

t_mlx	*set_mandel_params(t_mlx *data)
{
	data->min_re = -2.510;
	data->max_re = 2.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) \
		* data->y_height / data->x_width;
	return (data);
}

t_mlx	*set_julia_params(t_mlx *data)
{
	data->min_re = -2.3;
	data->max_re = 2.2077;
	data->min_im = -1.689;
	data->max_im = data->min_im + (data->max_re - data->min_re) \
		* data->y_height / data->x_width;
	data->k = 0.82942;
	return (data);
}

t_mlx	*image_init(t_mlx *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_width, data->y_height, \
																"Fract-ol");
	data->img = mlx_new_image(data->mlx, data->x_width, data->y_height);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	return (data);
}
