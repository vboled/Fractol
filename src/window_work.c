/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:02:41 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/08 14:02:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	test(t_frac *frac)
{
	create_mlx_image(frac);
}

int		mouse_hook(int key, int x, int y, void *param)
{
	if (key == 4 || key == 5)
		scale(param, key);
	put_mand(param);
	create_mlx_image(param);
	return (0);
}

int		deal_hook(int key, void *param)
{
	if (key == 53)
	{
		write(1, "EXIT", 4);
		free_struct(param);
		exit(0);
	}
	if (key >= 123 && key <= 126)
		shift(param, key, 0.05);
	if (key == 69 || key == 78)
		scale(param, key);
	put_mand(param);
	create_mlx_image(param);
	return (0);
}
