/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:02:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/19 16:43:48 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

t_mlx	*init_struct(void)
{
	t_mlx	*data;

	data = (t_mlx *)malloc(sizeof(t_mlx));
	data->iterations = 150;
	data->x_width = 1920;
	data->y_height = 1080;
	data->std_col = 0x00000000;
	data->main_col = 0x00000000;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->x_width, data->y_height, \
																"Fract-ol");
	data = image_init(data);
	printf("finished init\n");
	return (data);
}

t_mlx	*image_init(t_mlx *data)
{
	data->img = mlx_new_image(data->mlx, data->x_width, data->y_height);
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
	return (data);
}
