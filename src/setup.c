#include "../include/miniRT.h"

int	play(t_data data)
{
	mlx_t		*mlx;
	t_player	player;
	t_map3d		map3d;

	mlx = mlx_init(WIN_W, WIN_H, "Game", false);
	player.mlx = mlx;
	player.map3d = &map3d;
	set_player(&data, &player);
	if (!player.textures[0])
	{
		mlx_terminate(mlx);
		return (1);
	}
	mlx_image_to_window(mlx, player.img, 0, 0);
	draw_rays_3d(player);
	mlx_key_hook(mlx, &buttons, &player);
	mlx_loop(mlx);
	mlx_delete_image(mlx, player.img);
	delete_textures(&player);
	free_map(&map3d);
	mlx_terminate(mlx);
	return (0);
}