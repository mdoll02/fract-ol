/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/18 15:48:27 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_mlx	*init_struct(void)
{
	t_mlx	*data;

	data = (t_mlx *)malloc(sizeof(t_mlx));
	data->iterations = 50;
	data->x_width = 1920;
	data->y_height = 1080;
	data->col = 0x0000ff00;
	data->zoom = 1;
	data->move_x = -0.5;
	data->move_y = 0;
	data->x_index = -1;
	data->y_index = -1;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_width, data->y_height, \
																"Fract-ol");
	data = image_init(data);
	data->min_re = -2.0;
	data->max_re = 1.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) * \
		(data->y_height / data->x_width);
	data->re_factor = (data->max_re - data->min_re) / (data->x_width - 1);
	data->im_factor = (data->max_im - data->min_im) / (data->y_height - 1);
	printf("finished init\n");
	return (data);
}

t_mlx	*reset_values(t_mlx *data)
{
	data->c_re = data->min_re + data->x_index * data->re_factor;
	data->z_re = data->c_re;
	data->z_im = data->c_im;
	data->it = -1;
	return (data);
}


// t_mlx	*reset_values(t_mlx *data)
// {
// 	data->pr = 1.5 * (data->x_index - data->x_width / 2) / \
// 		(0.5 * data->zoom * data->x_width) + data->move_x;
// 	data->pi = (data->y_index - data->y_height / 2) / \
// 		(0.5 * data->zoom * data->y_height) + data->move_y;
// 	data->new_im = 0;
// 	data->new_re = 0;
// 	data->old_im = 0;
// 	data->old_re = 0;
// 	data->it = 0;
// 	return (data);
// }

t_mlx	*image_init(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx, data->x_width, data->y_height);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	return (data);
}
