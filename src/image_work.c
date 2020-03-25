/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:29:08 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/11 14:29:09 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	call_fractal(t_frac *frac)
{
	if (frac->type == 1)
		mandelbrot(frac);
	if (frac->type == 2)
	{
		mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFF0000,
		"For change real part of z press F/V");
		mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFF0000,
		"For change imaginary part of z press G/B");		
		julia(frac);
	}
	if (frac->type == 3)
		circle(frac);
}

void	create_mlx_image(t_frac *frac)
{
	mlx_clear_window(frac->mlx, frac->win);
	frac->num_of_str = 1;
	mlx_string_put(frac->mlx, frac->win, 30, 30 * frac->num_of_str++, 0xFF0000, "For change name of iter press A or Z");
	frac->pix_m = (int *)mlx_get_data_addr(frac->img,
	&(frac->bits_per_pixel), &(frac->size_line), &(frac->endian));
	call_fractal(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 400, 50);
}
