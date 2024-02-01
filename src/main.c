#include "fractol.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_display	display;
	// t_img		img;

	display.mlx_conn = mlx_init();
	// display.mlx_win = mlx_new_window(display.mlx_conn, 
	// 					WIDTH, HEIGHT, "Fractol");

	// img.img = mlx_new_image(display.mlx_conn, WIDTH, HEIGHT);
	// img.pix = mlx_get_data_addr(img.img, 
	// 					&img.bpp, &img.line_len, &img.endian);

	// mlx_loop(display.mlx_conn);

	mlx_destroy_display(display.mlx_conn);
	free(display.mlx_conn);
	return (0);
}
