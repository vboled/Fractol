/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:39:30 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 17:39:31 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_limited(double x, double y, int n)
{
	int i;
	double z_x;
	double z_y;
	double tmp_x;

	i = 0;
	z_x = x;
	z_y = y;
	while (i < n)
	{
		tmp_x = z_x * z_x - z_y * z_y + x;
		z_y = 2 * z_x * z_y + y;
		z_x = tmp_x;
		if ((z_x * z_x + z_y * z_y) > 4)
			return (i);
		i++;
	}
	return (i);
}

void	put_mand(t_frac *frac)
{
	int i;
	int j;
	double x;
	double y;

	i = 0;
	while (i < 1000)
	{
		j = 0;
		y = (double)(i - 500 + frac->shift_y) / frac->scale;
		while (j < 1000)
		{
			x = (double)(j - 500 + frac->shift_x) / frac->scale;
			frac->pix_m[i * 1000 + j] = put_color(frac, is_limited(x, y, frac->num_of_iter));
			j++;
		}
		i++;
	}
}