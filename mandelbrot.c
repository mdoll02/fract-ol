/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:27:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/19 15:07:24 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

// void	mandelbrot(t_mlx *data)
// {
// 	int		inside;
// 	double	z_re2;
// 	double	z_im2;

// 	printf("startet toasting\n");
// 	while (data->y_index++ < data->y_height)
// 	{
// 		data->c_im = data->max_im - data->y_index * data->im_factor;
// 		while (data->x_index++ < data->x_width)
// 		{
// 			data = reset_values(data);
// 			inside = 1;
// 			while (data->it++ < data->iterations)
// 			{
// 				z_re2 = data->z_re * data->z_re;
// 				z_im2 = data->z_im * data->z_im;
// 				if (z_re2 + z_im2 > 4)
// 				{
// 					inside = 0;
// 					break ;
// 				}
// 				data->z_im = 2 * data->z_re * data->z_im + data->c_im;
// 				data->z_re = z_re2 - z_im2 + data->c_re;
// 			}
// 			if (inside == 0)
// 				mlx_pixel_put(data->mlx, data->win, data->x_index, data->y_index, data->col);
// 		}
// 		data->x_index = 0;
// 	}
// 	printf("finished da BRED\n");
// 	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
// }

// void	mandelbrot(t_mlx *data)
// {
// 	printf("startet toasting\n");
// 	while (data->x_index++ < data->x_width)
// 	{
// 		while (data->y_index++ < data->y_height)
// 		{
// 			data = reset_values(data);
// 			while (data->it++ < data->iterations)
// 			{
// 				data->old_re = data->new_re;
// 				data->old_im = data->new_im;
// 				data->new_re = data->old_re * data->old_re - \
// 						data->old_im * data->old_im + data->pr;
// 				data->new_im = 2 * data->old_re * data->old_im + \
// 					data->pi;
// 				if ((data->new_re * data->new_re + data->new_im * \
// 						data->new_im) > 4)
// 					break ;
// 			}
// 			my_mlx_pixel_put(data, data->col);
// 			printf("Pixel is put o7\n");
// 		}
// 		data->y_index = 0;
// 	}
// 	printf("finished the BRED\n");
// 	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
// }

void mandelbrot(t_mlx *data)
{	
	mandel_init(data);	
	while(data->y < data->y_height)
	{
	    data->c_im = data->max_im - data->y * data->im_factor;
		data->x	= 0;
	    while (data->x < data->x_width)
	    {
			double c_re = data->min_re + data->x * data->re_factor;
	
	        double Z_re = c_re, Z_im = data->c_im;
	        int isInside = 1;
			data->it = 0;
	        while(data->it < data->iterations)
	        {
	            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
	            if(Z_re2 + Z_im2 > 4)
	            {
	                isInside = 0;
	                break;
	            }
	            Z_im = 2*Z_re*Z_im + data->c_im;
	            Z_re = Z_re2 - Z_im2 + c_re;
				data->it++;
	        }
			if (data->it == data->iterations)
				my_mlx_pixel_put(data, data->x, data->y, data->std_col); 
	        else
				my_mlx_pixel_put(data, data->x, data->y, 0x00ff0000); // my_mlx_color_put(data, x, y);
			data->x++;	
	    }
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	mandel_init(t_mlx *data)
{
	data->x = 0;
	data->y = 0;
	data->min_re = -2.0;
	data->max_re = 1.0;
	data->min_im = -1.2;
	data->max_im = data->min_im + (data->max_re - data->min_re) * data->y_height / data->x_width;
	data->re_factor = (data->max_re - data->min_re) / (data->x_width - 1);
	data->im_factor = (data->max_im - data->min_im) / (data->y_height - 1);
}

// void	mandel_calc(t_mlx *data)
// {
// 	double c_re = data->min_re + data->x * data->re_factor;
	
// 	        double Z_re = c_re, Z_im = data->c_im;
// 	        int isInside = 1;
// 			data->it = 0;
// }
