#include "../include/miniRT.h"

void	buttons(mlx_key_data_t key, void *param)
{
    mlx_t   *mlx;

    mlx = param;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(mlx);
}

int start(t_rt *rt)
{
    mlx_t   *mlx;

    printf("hi\n %i", rt->alight.rgb.r);
    mlx = mlx_init(WIN_W, WIN_H, "miniRT", false);
    mlx_image_t *image = mlx_new_image(mlx, WIN_W, WIN_H);
    mlx_image_to_window(mlx, image, 0, 0);
    mlx_key_hook(mlx, &buttons, mlx);
    mlx_loop(mlx);
    mlx_delete_image(mlx, image);
    mlx_terminate(mlx);
    return 0;
}

int main(int argc, char *argv[])
{
    if (argv != NULL) {
        argc = 1;
    }
    printf("Hello world!");
    t_rt rt;
    hardcode_data(&rt);
    printf("%i", ((t_shape *)rt.shapes->content)->rgb.b);
    
    free_shape_lst(&rt);
    start(&rt);
    return 0;
}