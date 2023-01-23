/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/23 13:41:57 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mlx	*init_struct(char **argv, int argc)
{
	t_mlx	*data;

	data = (t_mlx *)malloc(sizeof(t_mlx));
	data->iterations = 80;
	if (argc >= 2)
		data->x_width = ft_atoi(argv[1]);
	else
		data->x_width = 1920;
	data->y_height = data->x_width / 1.7777;
	data->std_col = 0x00000000;
	if (argc == 3)
		data->color_set = argv[2];
	else
		data->color_set = "red";
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_width, data->y_height, \
																"Fract-ol");
	data->min_re = -2.3;
	data->max_re = 2.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) \
		* data->y_height / data->x_width;
	data = image_init(data);
	return (data);
}

t_mlx	*image_init(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx, data->x_width, data->y_height);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	return (data);
}
