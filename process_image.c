/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:11:58 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/19 13:58:43 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	my_mlx_color_put(t_mlx *data, int x, int y)
{
	color_shift(data);
	my_mlx_pixel_put(data, x, y, data->dif_col);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->line_length + \
		x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}