#include "fractol.h"

void	frac_init(t_frac *frac)
{
	frac->shift_x = 0;
	frac->shift_y = 0;
	frac->num_of_iter = 30;
	frac->color_scheme = 0;
	frac->scale = 500;
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, 1100, 1100, "win1");
	frac->img = mlx_new_image(frac->mlx, 1000, 1000);
}

void	free_struct(t_frac *frac)
{
	if (frac)
	{
		if (frac->mlx)
			free(frac->mlx);
		if (frac->win)
			free(frac->win);
	}
}

int		mem_alloc(t_frac *frac)
{
	frac_init(frac);
	return (0);
}