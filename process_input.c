/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:27 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/19 16:33:21 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	process_k_input(int keycode, t_mlx *data)
{
	if (keycode == 4)
	{
		printf("HELP ME! PLS!");
		return (0);
	}
	if (keycode == 53)
	{
		ft_close(data);
	}
	return (0);
}

int	ft_close(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	write(2, "EXIT\n", 5);
	exit(0);
}
