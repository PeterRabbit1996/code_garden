#include <stdio.h>
#include <math.h>

double func_x_to_y(double x)
{
    double y = 0.0;

    if (x <= 0)
    {
        y = 0.0;
    }
    else if (x > 0 && x <= 10)
    {
        y = x;
    }
    else if (x >= 10)
    {
        y = 0.5 + sin(x);
    }
    else
    {

    }

    return y;
}

int main()
{
    double num_x = 0.0;
    double num_y = 0.0;

    printf("please input a num as input to function: ");
    scanf("%lf", &num_x);
    num_y = func_x_to_y(num_x);
    printf("the result is: %lf\n", num_y);

    return 0;
}
