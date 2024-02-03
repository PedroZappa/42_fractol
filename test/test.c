#include "test.h"

int main(int argc, char **argv)
{
	t_fractal test;
	int i = 0;
	long double xtemp;
	long double c;
	long double y;

	if (argc > 1)
	{
		c = atof(argv[1]);
	}
	else
	{
		c = 0.0;
		y = 0.0;
		test.c_x = -1;
		test.c_y = 0.1;
		test.z_old = 0;
		test.z_new = 0;
	}
	while(i < 10) {
		xtemp = (test.c_x * test.c_x) - (test.c_y * test.c_y) + c;
		test.c_y = (2 * test.c_x * test.c_y) + y;
		test.c_x = xtemp;
		printf("%d : (%Lf\t,  %Lf)\n", i, test.c_x,test.c_y);
		i++;
	}
	return (0);
}

