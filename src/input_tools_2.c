/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:04 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/31 11:36:07 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_move(t_mlx *data, int keycode)
{
	if (keycode == 123)
		move_left(data);
	if (keycode == 124)
		move_right(data);
	if (keycode == 125)
		move_down(data);
	if (keycode == 126)
		move_up(data);
	choose_set(data);
}

void	move_left(t_mlx *data)
{
	double	tmp_re;

	tmp_re = (data->max_re - data->min_re) * (-1);
	data->min_re += tmp_re / 8.5;
	data->max_re += tmp_re / 8.5;
}

void	move_right(t_mlx *data)
{
	double	tmp_re;

	tmp_re = (data->max_re - data->min_re);
	data->min_re += tmp_re / 8.5;
	data->max_re += tmp_re / 8.5;
}

void	move_down(t_mlx *data)
{
	double	tmp_im;

	tmp_im = (data->max_im - data->min_im) * (-1);
	data->min_im += tmp_im / 8.5;
	data->max_im += tmp_im / 8.5;
}

void	move_up(t_mlx *data)
{
	double	tmp_im;

	tmp_im = (data->max_im - data->min_im);
	data->min_im += tmp_im / 8.5;
	data->max_im += tmp_im / 8.5;
}
