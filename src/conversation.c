/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 17:23:36 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 17:23:38 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scale(t_frac *frac, int key)
{
	if (key == 69)
		frac->scale += 500;
	else if (key == 78)
		frac->scale -= 500;
	else if (key == 5)
		frac->scale += 500;
	else
		frac->scale -= 500;	
	if (frac->scale <= 0)
		frac->scale = 300;
}

void	shift(t_frac *frac, int key, double step)
{
	if (key == 123)
		frac->shift_x -= 125;
	if (key == 124)
		frac->shift_x += 125;
	if (key == 125)
		frac->shift_y += 125;
	if (key == 126)
		frac->shift_y -= 125;
}
