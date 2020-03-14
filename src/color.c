/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 18:50:27 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/14 19:00:46 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			get_light(int begin, int end, double percent)
{
	return ((1 - percent) * end + percent * begin);
}

int			get_color(int begin, int end, double percent)
{
	int		red;
	int		blue;
	int		green;

	if (percent == 1.0)
		return (0);
	red = get_light(begin >> 16 & 255, end >> 16 & 255, percent);
	green = get_light(begin >> 8 & 255, end >> 8 & 255, percent);
	blue = get_light(begin & 255, end & 255, percent);
	return ((red << 16) | (green << 8) | blue);
}

int			color0(int num_of_iter, int iter)
{
	double percentage;

	percentage = (double)iter / num_of_iter;
	if (iter % 2)
		return (get_color(0x0000FF, 0xFF0000, percentage));
	return (get_color(0xFF0000, 0x0000FF, percentage));
}

int			color1(int num_of_iter, int iter)
{
	double percentage;

	percentage = (double)iter / num_of_iter;
	if (iter % 2)
		return (get_color(0x0000FF, 0xFF0000, percentage));
	if (iter % 3)
		return (get_color(0x00FF00, 0xFF0000, percentage));
	if (iter % 5)
		return (get_color(0xFFF200, 0xFF0000, percentage));
	return (get_color(0xFF0000, 0x0000FF, percentage));
}

int			put_color(t_frac *frac, int iter)
{
	if (frac->color_scheme == 0)
		return (color0(frac->num_of_iter, iter));
	if (frac->color_scheme == 1)
		return (color1(frac->num_of_iter, iter));
	return (0);
}

