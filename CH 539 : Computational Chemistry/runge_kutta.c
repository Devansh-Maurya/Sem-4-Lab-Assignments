#include<stdio.h>

#define H 0.005

float f(float, float);

int main()
{
    float x, y, finalx, k1, k2, k3, k4;

    printf("Enter initial value of x: ");
    scanf("%f", &x);

    printf("Enter initial value of y: ");
    scanf("%f", &y);

    printf("Enter value of x till wHere you want to calculate: ");
    scanf("%f", &finalx);

    while(x < finalx)
    {
        k1 = f(x, y);
        k2 = f(x + H/2, y + k1/2);
        k3 = f(x + H/2, y + k2/2);
        k4 = f(x + H, y + k3);

        y = y + H*(k1 + 2*k2 + 2*k3 + k4)/6;

        printf("%f\t%f\n", x, y);

        x = x + H;
    }
}

float f( float x, float y)
{
    return (x - y)/2;
}