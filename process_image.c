/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:11:58 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/18 16:14:56 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	// printf("Puttin da piksel\n");
	dst = data->img_addr + (y * data->line_length + \
		x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
