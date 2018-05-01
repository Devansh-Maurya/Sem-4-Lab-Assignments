#include<stdio.h>

#define S 10

void insertion(int *, int);

int main()
{
    int n, i, a[S];

    printf("Enter the size: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    insertion(a, n);

    printf("The sorted elements: ");
    for(i=0; i<n; i++)
        printf("%d ", a[i]);

    return 0;
}

void insertion(int *a, int n)
{
    int i, j, k;

    for(i=1; i<n; i++)
    {
        k = a[i];

        for(j = i-1; (j>=0) && (a[j] > k); j--)
        {
           a[j+1] = a[j];
        }
        a[j+1] = k;
    }
}