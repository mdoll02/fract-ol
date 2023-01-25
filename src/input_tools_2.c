/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_tools_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:04 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/25 16:24:53 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	move(t_mlx *data, int keycode)
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
	data->min_re -= 0.001;
	data->max_re -= 0.001;
}

void	move_right(t_mlx *data)
{
	data->min_re += 0.001;
	data->max_re += 0.001;
}

void	move_down(t_mlx *data)
{
	data->min_im -= 0.001;
	data->max_im -= 0.001;
}

void	move_up(t_mlx *data)
{
	data->min_im += 0.001;
	data->max_im += 0.001;
}
