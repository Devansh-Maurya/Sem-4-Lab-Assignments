#include <stdio.h>
#include<math.h>

#define S 10

struct complex
{
    float real;
    float imaginary;
};

typedef struct complex complex;

void dft(float *, int);

int main()
{
    int i, n;
    float a[S];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the coefficients:\n");
    for(i=0; i<n; i++)
    {
        scanf("%f", &a[i]);
    }

    dft(a, n);

    return 0;
}

void dft(float *a, int n)
{
    complex solution[S];
    int i, j;

    if(n==1)
    {
        printf("%f\n", a[0]);
    }
    else
    {
        for(i=0; i<n; i++)
        {
            solution[i].real = solution[i].imaginary = 0;

            for(j=0; j<n; j++)
            {
                solution[i].real += a[j]*cos(2*M_PI*i*j/n);
                solution[i].imaginary += a[j]*sin(2*M_PI*i*j/n);
            }
        }

        for(i=0; i<n; i++)
            printf("%f + %fi\n", solution[i].real, solution[i].imaginary);
    }

}