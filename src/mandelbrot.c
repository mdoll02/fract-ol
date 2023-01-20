/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:27:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/20 10:53:16 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_mlx *data)
{	
	mandel_init(data);
	while (data->y < data->y_height)
	{
		data->c_im = data->max_im - data->y * data->im_factor;
		data->x = 0;
		while (data->x < data->x_width)
		{
			mandel_calc(data);
			while (data->it < data->iterations)
			{
				if ((data->z_re * data->z_re) + (data->z_im * data->z_im) > 4)
					break ;
				mandel_calc_2(data);
			}
			if (data->it == data->iterations)
				my_mlx_pixel_put(data, data->x, data->y, data->std_col);
			else
				color_shift(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	mandel_init(t_mlx *data)
{
	data->x = 0;
	data->y = 0;
	data->min_re = -2.3;
	data->max_re = 2.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) * \
		data->y_height / data->x_width;
	data->re_factor = (data->max_re - data->min_re) / (data->x_width - 1);
	data->im_factor = (data->max_im - data->min_im) / (data->y_height - 1);
}

void	mandel_calc(t_mlx *data)
{
	data->c_re = data->min_re + data->x * data->re_factor;
	data->z_re = data->c_re;
	data->z_im = data->c_im;
	data->it = 0;
}

void	mandel_calc_2(t_mlx *data)
{
	double	tmp;

	tmp = (data->z_re * data->z_re) - (data->z_im * data->z_im);
	data->z_im = 2 * data->z_re * data->z_im + data->c_im;
	data->z_re = tmp + data->c_re;
	data->it++;
}
