/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:03:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/21 13:51:25 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	red_pallet(t_mlx *data)
{
	double	r;
	double	g;

	if (data->it >= 15)
		r = 255;
	else
		r = data->it * 17;
	g = data->it * 5;
	return (create_trgb(0, r, g, 0));
}

int	green_pallet(t_mlx *data)
{
	double	g;
	double	b;

	if (data->it >= 15)
		g = 255;
	else
		g = data->it * 17;
	b = data->it * 5;
	return (create_trgb(0, 0, g, b));
}

int	blue_pallet(t_mlx *data)
{
	double	b;
	double	r;

	if (data->it >= 15)
		b = 255;
	else
		b = data->it * 17;
	r = data->it * 5;
	return (create_trgb(0, r, 0, b));
}

int	idk_wtf_this_is(t_mlx *data)
{
	double	b;

	b = 255 - (255 / data->it);
	return (create_trgb(0, b, b, b));
}

int	black_white(t_mlx *data)
{
	double			b;
	unsigned char	tmp;

	b = 255 - (255 / (double)data->it);
	tmp = (unsigned char)b;
	return (create_trgb(0, tmp, tmp, tmp));
}
