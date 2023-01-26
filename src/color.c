/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:10:52 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/26 11:54:45 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	get_color(t_mlx *data)
{
	int	color;

	color = 0;
	if (ft_strncmp(data->color_set, "red", 20) == 0)
		color = red_pallet(data);
	if (ft_strncmp(data->color_set, "green", 20) == 0)
		color = green_pallet(data);
	if (ft_strncmp(data->color_set, "blue", 20) == 0)
		color = blue_pallet(data);
	if (ft_strncmp(data->color_set, "idk", 20) == 0)
		color = idk_wtf_this_is(data);
	if (ft_strncmp(data->color_set, "bw", 20) == 0)
		color = black_white(data);
	my_mlx_pixel_put(data, data->x, data->y, color);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
