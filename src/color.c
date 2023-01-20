/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:10:52 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/20 14:22:04 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Range of (r) 100 - 255 (g) 0 - 255 (b) 0 - 255 --> ca.656 colors?? 
// (r) #800000 - ff0000 / (g) ff0000 - ffff00 / (b) ffff00 - ffffff

t_color	*init_color(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(color));
	return (color);
}

void	color_shift(t_mlx *data)
{
	t_color		*color;
	double		shift;

	color = init_color();
	shift = (double)round((data->it / data->iterations) * 64);
	data->dif_col = create_trgb(shift);
	printf("%x\n", data->dif_col);
	free(color);
	my_mlx_pixel_put(data, data->x, data->y, data->dif_col);
}

void	get_trgb(t_color *color, int dif_col)
{
	color->t = dif_col >> 24 & 0xFF;
	color->r = dif_col >> 16 & 0xFF;
	color->g = dif_col >> 8 & 0xFF;
	color->b = dif_col & 0xFF;
}

unsigned int	create_trgb(double shift)
{
	return (0x000F0F0F + ((shift / 2) * 0x00080808));
}

void	color(t_mlx *data, double shift)
{
	shift = data->bits_per_pixel;
}
