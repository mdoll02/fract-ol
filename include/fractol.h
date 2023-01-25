/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:11:43 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/25 10:25:28 by mdoll            ###   ########.fr       */
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
	char				*color_set;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					iterations;
	int					x_width;
	int					y_height;
	unsigned int		std_col;
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
	int					fractal;
	double				k;
	double				tmp_array[5];
}			t_mlx;

// PROCESS INPUT
int				process_k_input(int keycode, t_mlx *data);
int				process_m_input(int keycode, int x, int y, t_mlx *data);
int				ft_close(t_mlx *data);

// INPUT TOOLS
void			zoom(t_mlx *data, int x, int y, int direction);
void			change_interface(t_mlx *data);
void			change_color(int keycode, t_mlx *data);
void			choose_set(t_mlx *data);
void			reset_values(t_mlx *data);

// Init
t_mlx			*init_struct(int argc, char **argv);
t_mlx			*image_init(t_mlx *data);
t_mlx			*set_mandel_params(t_mlx *data);
t_mlx			*set_julia_params(t_mlx *data);
t_mlx			*set_burning_ship_params(t_mlx *data);

// Mandelbrot
void			mandelbrot(t_mlx *data);
void			mandel_init(t_mlx *data);
void			mandel_calc(t_mlx *data);
void			mandel_calc_2(t_mlx *data);

// Julia
void			julia(t_mlx *data);
void			julia_init(t_mlx *data);
void			julia_calc(t_mlx *data);
void			julia_calc_2(t_mlx *data);

// Burning ship
void			burning_ship(t_mlx *data);
void			burning_ship_init(t_mlx *data);
void			burning_ship_calc_2(t_mlx *data);
void			burning_ship_calc(t_mlx *data);

// Image
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

// color
void			get_color(t_mlx *data);
int				create_trgb(int t, int r, int g, int b);

// color pallet
int				red_pallet(t_mlx *data);
int				green_pallet(t_mlx *data);
int				blue_pallet(t_mlx *data);
int				idk_wtf_this_is(t_mlx *data);
int				black_white(t_mlx *data);

// handel parameter
int				check_parameters(int argc, char **argv);
int				compare_parameters(int argc, char **argv);
void			print_param_options(void);

#endif