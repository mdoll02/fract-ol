/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:01:27 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/17 15:38:30 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	process_k_input(int keycode, t_mlx *data)
{
	if (keycode == 4)
	{
		help(data);
		return (0);
	}
	if (keycode == 30)
	{
		printf("ZOOM IN!");
	}
	if (keycode == 30)
	{
		printf("ZOOM OUT!");
	}
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data);
		exit(0);
	}
	return (0);
}

int	close(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data);
	exit(0);
}

void	help(t_mlx *data)
{
	mlx_string_put(data->mlx, data->win, 500, 1000, 255, "HELP ME");
}
