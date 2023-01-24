/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:31:30 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/24 11:08:53 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	check_parameters(int argc, char **argv)
{
	if (compare_parameters(argc, argv) == -1)
	{
		print_param_options();
		return (-1);
	}
	return (1);
}

int	compare_parameters(int argc, char **argv)
{
	int	sum_fract;
	int	sum_col;

	if (argc < 4 || argc > 5)
		return (-1);
	sum_fract = ft_strncmp(argv[1], "mandelbrot", 20) * \
		ft_strncmp(argv[1], "julia", 20);
	sum_col = ft_strncmp(argv[2], "red", 20) * ft_strncmp(argv[2], "green", 20) \
		* ft_strncmp(argv[2], "blue", 20) * ft_strncmp(argv[2], "idk", 20) * \
			ft_strncmp(argv[2], "bw", 20);
	if (!ft_atoi(argv[argc - 1]) || ft_atoi(argv[argc - 1]) > 1440 \
		|| ft_atoi(argv[argc - 1]) < 480)
		return (-1);
	if (sum_fract != 0 || sum_col != 0)
		return (-1);
	return (1);
}

void	print_param_options(void)
{
	write(1, "----------Wrong Input----------\n", 32);
	write(1, "1. Paramter: Fractal\nmandelbrot / julia\n", 41);
	write(1, "2. Parameter: Color set\nred / green / blue / idk / bw\n", 55);
	write(1, "3. Parameter: Width\n480 <-> 1440\n", 34);
}
