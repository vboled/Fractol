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

#include "../includes/fractol.h"

int		deal_hook(int key, t_frac *param)
{
	if (key == 65307)
		destroy_window(param);
	if (param->type != -1)
	{
		if (key == 113 && param->type == 2)
			change_role(param);
		if (key == 103 || key == 98)
			change_dragon(param, key);
		if (key >= 65361 && key <= 65364)
			shift(param, key, 0.05);
		if (key == 65451 || key == 65453)
			scale_key(param, key);
		if (key == 97 || key == 122)
			change_iter(param, key);
		if (key == 119)
			change_color(param);
		create_mlx_image(param);
	}
	return (0);
}
