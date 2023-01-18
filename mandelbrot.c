/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:27:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/18 16:19:04 by mdoll            ###   ########.fr       */
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
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe) * data->y_height / data->x_width;
	double Re_factor = (MaxRe-MinRe)/( data->x_width-1);
	double Im_factor = (MaxIm-MinIm)/(data->y_height -1);
	
	for(int y=0; y<data->y_height; ++y)
	{
	    double c_im = MaxIm - y*Im_factor;
	    for(int x=0; x< data->x_width; ++x)
	    {
	        double c_re = MinRe + x*Re_factor;
	
	        double Z_re = c_re, Z_im = c_im;
	        int isInside = 1;
	        for(int n=0; n<data->iterations; ++n)
	        {
	            double Z_re2 = Z_re*Z_re, Z_im2 = Z_im*Z_im;
	            if(Z_re2 + Z_im2 > 4)
	            {
	                isInside = 0;
	                break;
	            }
	            Z_im = 2*Z_re*Z_im + c_im;
	            Z_re = Z_re2 - Z_im2 + c_re;
	        }
	        if(isInside == 1) { my_mlx_pixel_put(data, x, y, data->col); }
	    }
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}