/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:27:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/17 16:01:33 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fractol.h"

int	mandelbrot(t_mlx *data)
{
	double MinRe = -2.0;
	double MaxRe = 1.0;
	double MinIm = -1.2;
	double MaxIm = MinIm+(MaxRe-MinRe) * data->y_height/data->x_width;
	double Re_factor = (MaxRe-MinRe) / (data->x_width-1);
	double Im_factor = (MaxIm-MinIm) / (data->y_height-1);
	
	for(unsigned y=0; y<data->y_height; ++y)
	{
	    double c_im = MaxIm - y*Im_factor;
	    for(unsigned x=0; x<data->x_width; ++x)
	    {
	        double c_re = MinRe + x*Re_factor;
	
	        double Z_re = c_re, Z_im = c_im;
	        int isInside = 1;
	        for(unsigned n=0; n<data->iterations; ++n)
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
	        if(isInside)
			{
				mlx_pixel_put(data->mlx, data->win, x, y, data->col);
			}
	    }
	}
	return (0);
}
