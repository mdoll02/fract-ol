/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:43 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/20 11:57:59 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

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
	int					std_col;
	int					main_col;
	int					dif_col;
	int					it;
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
	int					y;
	int					x;
}			t_mlx;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}			t_color;

// PROCESS INPUT
int				process_k_input(int keycode, t_mlx *data);
int				ft_close(t_mlx *data);
void			change_interface(t_mlx *data);

// Init
t_mlx			*init_struct(void);
t_color			*init_color(void);
t_mlx			*image_init(t_mlx *data);
void			mandel_init(t_mlx *data);

// Mandelbrot
void			mandelbrot(t_mlx *data);
void			mandel_calc(t_mlx *data);
void			mandel_calc_2(t_mlx *data);

// Image
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

// color
void			color_shift(t_mlx *data);
void			color(t_mlx *data, double shift);
void			get_trgb(t_color *color, int dif_col);
int				create_trgb(int t, int r, int g, int b);

#endif