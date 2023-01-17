/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:43 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/17 16:01:18 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	unsigned int		iterations;
	unsigned int		x_width;
	unsigned int		y_height;
	int					col;
}			t_mlx;

// PROCESS INPUT
int		process_k_input(int keycode, t_mlx *data);
int		close(t_mlx *data);
void	help(t_mlx *data);
t_mlx	*init_struct(void);
int		mandelbrot(t_mlx *data);




#endif