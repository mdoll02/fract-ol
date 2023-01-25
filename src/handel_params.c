/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:31:30 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/25 16:02:25 by mdoll            ###   ########.fr       */
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
		ft_strncmp(argv[1], "julia", 20) * \
		ft_strncmp(argv[1], "burning ship", 20);
	sum_col = ft_strncmp(argv[2], "red", 20) * ft_strncmp(argv[2], "green", 20) \
		* ft_strncmp(argv[2], "blue", 20) * ft_strncmp(argv[2], "idk", 20) * \
			ft_strncmp(argv[2], "bw", 20);
	if (!ft_atoi(argv[3]) || ft_atoi(argv[3]) > 1440 \
		|| ft_atoi(argv[3]) < 480)
		return (-1);
	if (sum_fract != 0 || sum_col != 0)
		return (-1);
	if (argc == 5)
	{
		if (ft_strncmp(argv[1], "julia", 20) != 0 || \
			!ft_atoi(argv[4]) || ft_atoi(argv[4]) > 80 || ft_atoi(argv[4]) < 0)
			return (-1);
	}
	return (1);
}

void	print_param_options(void)
{
	write(1, "----------Wrong Input----------\n", 32);
	write(1, "1. Paramter: Fractal\nmandelbrot / julia\n", 41);
	write(1, "2. Parameter: Color set\nred / green / blue / idk / bw\n", 55);
	write(1, "3. Parameter: Width\n480 <-> 1440\n", 34);
	write(1, "4. Parameter: Only for Julia set\n 1 <-> 80\n", 43);
}
