/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:31:30 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/26 10:08:55 by mdoll            ###   ########.fr       */
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
			!ft_atoi(argv[4]) || ft_atoi(argv[4]) > 40 || ft_atoi(argv[4]) < 20)
			return (-1);
	}
	return (1);
}

void	print_param_options(void)
{
	write(1, "----------Wrong Input----------\n", 32);
	write(1, "1. Paramter: Fractal\nmandelbrot / julia / burning ship"\
			" (you need to wirte it in double quotes)\n", 96);
	write(1, "2. Parameter: Color set\nred / green / blue / idk / bw\n", 55);
	write(1, "3. Parameter: Width\n480 <-> 1440\n", 34);
	write(1, "4. Parameter: Only for Julia set\n 20 <-> 40\n", 45);
}

void	display_help_message(void)
{
	write(1, "----------HELP----------\n"\
			"Use: 1 / 2 / 3 / 4 / 5 \t\tto change the color set\n"\
			"Use: r \t\t\t\tto reset the fractal position\n"\
			"Use: left mouse-button \t\tclick into the mlx"\
			" window to change the Julia set\n"\
			"Use: arrow-keys\t\t\tto move the fractal set\n"\
			"Use: + / - \t\t\tto increase / decrease the number"\
			" of iterations\n"\
			"Use: scroll-wheel\t\tto zoom in / out\n", 331);
}
