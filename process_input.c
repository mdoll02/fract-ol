/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:27 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/18 10:47:55 by mdoll            ###   ########.fr       */
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
		close(data);
	}
	return (0);
}

int	close(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}
