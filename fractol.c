/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:56:25 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/17 12:11:03 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "./fractol.h"

int	main(void)
{
	t_mlx	*data;
	int		x;
	int		y;
	int		col;

	data = (t_mlx *)malloc(sizeof(t_mlx));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Frac-ol");
	x = 0;
	y = 0;
	col = 0;
	while (x <= 1920)
	{
		while (y <= 1080)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, col);
			y++;
			col++;
		}
		col = 0;
		y = 0;
		x++;
	}
	mlx_hook(data->win, event, mask, func, param);
	mlx_loop(data->mlx);
}


