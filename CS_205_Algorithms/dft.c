#include<stdio.h>
#include<math.h>

#define S 10

struct complex
{
    double real;
    double imaginary;
};

typedef struct complex complex;

void discreteFourierTransform(float [], int);

int main()
{
    int i, n;

    float a[S];
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i=0; i<n; i++)
        scanf("%f", &a[i]);
    
    discreteFourierTransform(a, n);
}

void discreteFourierTransform(float a[], int n)
{
    complex w, wn, s, y[S];
    double twoPIn = M_PI*2/n, calc = M_PI*2/n;

    if(n==1)
        printf("%f", a);
    else
    {
        int j, i;

        w.real = w.imaginary = 1;
        
        for(i=0; i<n; i++)
        {
            s.real = 0;
            s.imaginary = 0;
            
            for(j=0; j<n; j++)
            {
                s.real = s.real + a[j]*cos(2*M_PI*j*i/n);
                s.imaginary = s.imaginary + a[j]*sin(2*M_PI*j*i/n);
            }
        }

        for(i=0; i<n; i++)
        {
            printf("%f + %fi\n", y[i].real, y[i]. imaginary);
        }
    }
}