#include<stdio.h>

void fact(int, int);

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);

    printf("Factorial(%d)= ", n);
    fact(n, 1);

    return 0;
}

void fact(int n, int a)
{
    if((n==1)||(n==0))
    {   
        printf("%d\n", a);
    }
    else
        fact(n-1, n*a);
}