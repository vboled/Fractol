#include "../includes/fractol.h"

int		deal_hook(int key, t_frac *param)
{
    printf("###");
	if (key == 65307) //53
		destroy_window(param);
	if (param->type != -1)
	{
		if (key == 113)
			change_role(param);
		if (key >= 65361 && key <= 65364) //123 126
			shift(param, key, 0.05);
		if (key == 65451 || key == 65453) //69 78
			scale_key(param, key);
		if (key == 97 || key == 122) // A, Z
			change_iter(param, key);
		create_mlx_image(param);
	}
	return (0);
}