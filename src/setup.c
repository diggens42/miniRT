#include "../include/miniRT.h"

int	run_mlx(t_rt *rt)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(W_WIDTH, W_HEIGHT, "miniRT", false);
	if (!mlx)
		return (1);
	image = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	if (!image)
	{
		mlx_terminate(mlx);
		return (1);
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
