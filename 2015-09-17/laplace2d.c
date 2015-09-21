#include <stdio.h>
#include <math.h>


double u(double x, double y)
{
    return cos(x) * sin(y);
}


double laplacian_u(double (*u)(double x, double y),
                   double h, double x, double y)
{
	double laplacian_x, laplacian_y;
	laplacian_x = (1/(h^2))*(u(x-h,y) - 2*u(x,y) + u(x+h,y));
	laplacian_y = (1/(h^2))*(u(x,y-h) - 2*u(x,y) + u(x,y+h));
	return laplacian_x + laplacian_y;
}


int main()
{
    printf("Numerical Laplacian at (0.8,0.5) = %g\n",
           laplacian_u(u, 1e-3, 0.8, 0.5));
    printf("True Laplacian at (0.8,0.5) = %g\n",
           2 * cos(0.8) * sin(0.5));
    return 0;
}
