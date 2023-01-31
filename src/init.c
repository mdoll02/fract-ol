/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/31 11:36:10 by mdoll            ###   ########.fr       */
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
		set_mandel_params(data);
	if (ft_strncmp(argv[1], "julia", 20) == 0)
	{
		if (argc == 5)
			data->k = (double)ft_atoi(argv[4]) * 0.0123456789;
		else
			data->k = 0.4042832;
		set_julia_params(data);
	}
	if (ft_strncmp(argv[1], "burning ship", 20) == 0)
		set_burning_ship_params(data);
	return (data);
}

t_mlx	*set_mandel_params(t_mlx *data)
{
	data->fractal = 0;
	data->min_re = -2.510;
	data->max_re = 2.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) \
		* data->y_height / data->x_width;
	data->tmp_array[0] = data->min_re;
	data->tmp_array[1] = data->max_re;
	data->tmp_array[2] = data->min_im;
	data->tmp_array[3] = data->max_im;
	return (data);
}

t_mlx	*set_burning_ship_params(t_mlx *data)
{
	data->fractal = 2;
	data->min_re = 3.00255;
	data->max_re = -2.862231;
	data->min_im = 0.953864;
	data->max_im = data->min_im + (data->max_re - data->min_re) \
		* data->y_height / data->x_width;
	data->tmp_array[0] = data->min_re;
	data->tmp_array[1] = data->max_re;
	data->tmp_array[2] = data->min_im;
	data->tmp_array[3] = data->max_im;
	return (data);
}

t_mlx	*set_julia_params(t_mlx *data)
{
	data->fractal = 1;
	data->min_re = -2.3;
	data->max_re = 2.2077;
	data->min_im = -1.689;
	data->max_im = data->min_im + (data->max_re - data->min_re) \
		* data->y_height / data->x_width;
	data->tmp_array[0] = data->min_re;
	data->tmp_array[1] = data->max_re;
	data->tmp_array[2] = data->min_im;
	data->tmp_array[3] = data->max_im;
	data->tmp_array[4] = data->k;
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
