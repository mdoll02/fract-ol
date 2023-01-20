/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:10:52 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/20 11:29:49 by mdoll            ###   ########.fr       */
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
	t_color	*color;
	int		shift;

	color = init_color();
	if (data->it == 0)
		shift = 0;
	else
		shift = data->iterations - data->it;
	get_trgb(color, data->dif_col);
	data->dif_col = (create_trgb(255 * shift, 255 + shift, 255 \
		+ shift, 255 + shift));
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	color(t_mlx *data, double shift)
{
	shift = data->bits_per_pixel;
}
