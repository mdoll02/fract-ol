/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:03:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/02/27 09:23:31 by mdoll            ###   ########.fr       */
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
	g = data->it * 3;
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
	b = data->it * 3;
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
	r = data->it * 4;
	return (create_trgb(0, r, 0, b));
}

int	idk_wtf_this_is(t_mlx *data)
{
	double		r;
	double		g;
	double		b;
	double		m;

	if (data->it < 20)
		m = (double)data->it / data->iterations;
	else
		m = 2;
	r = m * pow((sin(0.9 * data->it + 16) * 255 + 255), 2);
	g = m * pow((sin(0.5 * data->it + 8) * 255 + 255), 2);
	b = m * (sin(0.3 * data->it + 4) * 255 + 255);
	return (create_trgb(0, r, g, b));
}

int	black_white(t_mlx *data)
{
	double	s;

	s = (double)data->it / (double)data->iterations;
	return (create_trgb(0, s * 255, s * 255, s * 255));
}
