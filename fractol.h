/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:43 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/18 16:08:20 by mdoll            ###   ########.fr       */
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
	void				*img;
	char				*img_addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					iterations;
	int					x_width;
	int					y_height;
	int					col;
	double				pi;
	double				pr;
	double				new_re;
	double				new_im;
	double				old_re;
	double				old_im;
	double				zoom;
	double				move_x;
	double				move_y;
	int					y_index;
	int					x_index;
	int					it;
	// TEST ZONE
	double				min_re;
	double				max_re;
	double				min_im;
	double				max_im;
	double				re_factor;
	double				im_factor;
	double				c_im;
	double				c_re;
	double				z_im;
	double				z_re;
}			t_mlx;

// PROCESS INPUT
int				process_k_input(int keycode, t_mlx *data);
t_mlx			*init_struct(void);
int				close(t_mlx *data);

// Init
t_mlx			*init_struct(void);
t_mlx			*reset_values(t_mlx *data);
t_mlx			*image_init(t_mlx *data);

// Mandelbrot
void			mandelbrot(t_mlx *data);

// Image
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

#endif