#include <stdio.h>

#define S 4

struct complex
{
    float real;
    float imag;
};

void input(struct complex*);
void display(struct complex);
struct complex sum(struct complex, struct complex);
struct complex product(struct complex, struct complex);

int main()
{
    struct complex A[S][S], At[S][S], C[S][S];
    int i,j,k;
    printf("Enter the elements of matrix\n\n");
    for(i=1; i<S; i++)
     {
       for(j=1; j<S; j++)
        {
            printf("Enter element A[%d][%d]",i,j);
            input(&A[i][j]);
            At[j][i].real=A[i][j].real;
            At[j][i].imag=A[i][j].imag;
        }
       
     }

    printf("The matrix that you entered is\n\n");
    for(i=1; i<S; i++)
    {
        for(j=1; j<S; j++)
        {
            display(A[i][j]);
            if(A[i][j].imag)
            At[j][i].imag=(-A[i][j].imag);
            printf(" ");
        }
        printf("\n");
    }

    printf("The conjugate transpose matrix is\n\n");
    for(i=1; i<S; i++)
    {
        for(j=1; j<S; j++)
        {
            display(At[i][j]);
            printf(" ");
        }
        printf("\n");
    }

    //product
    printf("\nThe product matrix is\n\n");
    for(i=1; i<S; i++)
    {
        for(j=1; j<S; j++)
        {
            C[i][j].real=0;
            C[i][j].imag=0;
            for(k=1; k<S; k++)
            {
                C[i][j].real+=At[i][k].real*A[k][j].real -At[i][k].imag*A[k][j].imag;
                C[i][j].imag+=At[i][k].real*A[k][j].imag +At[i][k].imag*A[k][j].real; 
            }
            display(C[i][j]);
            printf(" ");
            
        }
        printf("\n");
    }
    return 0;
} 

void input(struct complex *t)
{
    printf("\nEnter value in\n");
    printf("real part : ");
    scanf("%f", &t->real);
    printf("imaginary part : ");
    scanf("%f", &t->imag);
} 

void display(struct complex c)
{
    printf("%g + %gi", c.real, c.imag);
} 

struct complex sum(struct complex t1, struct complex t2)
{
    struct complex t;
    t.real = t1.real + t2.real;
    t.imag = t1.imag + t2.imag;
    return t;
} 

struct complex product(struct complex t1, struct complex t2)
{
    struct complex t;
    t.real = t1.real * t2.real - t1.imag * t2.imag;
    t.imag = t1.real * t2.imag + t1.imag * t2.real;
    return t;
}