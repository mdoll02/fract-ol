/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:53:38 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/30 12:27:28 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	burning_ship(t_mlx *data)
{
	mlx_clear_window(data->mlx, data->win);
	burning_ship_init(data);
	while (data->y < data->y_height)
	{
		data->x = 0;
		while (data->x < data->x_width)
		{
			burning_ship_calc(data);
			while (data->it < data->iterations && (data->z_re * data->z_re) + \
				(data->z_im * data->z_im) <= 4)
				burning_ship_calc_2(data);
			if (data->it == data->iterations)
				my_mlx_pixel_put(data, data->x, data->y, data->std_col);
			else
				get_color(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	burning_ship_init(t_mlx *data)
{
	data->x = 0;
	data->y = 0;
	data->re_factor = (data->max_re - data->min_re) / (data->x_width - 1);
	data->im_factor = (data->max_im - data->min_im) / (data->y_height - 1);
}

void	burning_ship_calc(t_mlx *data)
{
	data->c_im = data->max_im - data->y * data->im_factor;
	data->c_re = data->min_re + data->x * data->re_factor;
	data->z_re = data->c_re;
	data->z_im = data->c_im;
	data->it = 0;
}

void	burning_ship_calc_2(t_mlx *data)
{
	double	tmp;

	tmp = pow(data->z_re, 2) - pow(data->z_im, 2);
	data->z_im = fabs(2 * data->z_re * data->z_im) + data->c_im;
	data->z_re = tmp + data->c_re;
	data->it++;
}
