#include "fractol.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_display	display;

	display.mlx_conn = mlx_init();
	display.mlx_win = mlx_new_window(display.mlx_conn, 
						WIDTH, HEIGHT, "Fractol");

	return (0);
}
