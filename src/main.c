/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfork <rfork@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:13:18 by rfork             #+#    #+#             */
/*   Updated: 2020/01/13 20:23:37 by dovran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractol.h"

void	print_param(t_frac *frac)
{
	while (frac)
	{
		printf("%d, ", frac->type);
		frac = frac->next;
	}
	printf("\n");
}

int		check_param(char *str, t_frac **frac)
{
	if (!ft_strcmp(str, "mandelbrot") && !add_frac(frac, 1))
		return (0);
	if (!ft_strcmp(str, "julia") && !add_frac(frac, 2))
		return (0);
	if (!ft_strcmp(str, "circle") && !add_frac(frac, 3))
		return (0);
	return (1);
}

int		check_input_data(int argc, char **argv, t_frac **frac)
{
	if (argc < 2)
		return (0);
	while (argc > 1)
	{
		argv++;
		if (!check_param(*argv, frac))
		{
			write(1, "ERROR\n", 6);
			return (0);
		}
		argc--;
	}
	if ((*frac))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_frac	*frac;
	void	*mlx;

	frac = NULL;
	if (check_input_data(argc, argv, &frac))
	{
		mlx = frac->mlx;
		while (frac)
		{
			mlx_hook(frac->win, 2, 5, deal_hook, frac);
			mlx_hook(frac->win, 4, 3, mouse_hook, frac);
			create_mlx_image(frac);
			frac = frac->next;
		}
		mlx_loop(mlx);
	}
	else
		write(1, "There are commands:\nmandelbrot, julia, circle\n", 46);	
	return (0);
}

