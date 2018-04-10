//INPUT = n and k
//Create an array of size n with elements from 1 to k
//The elements should be in non-decreasing order
//Print all the possible combinations and total number of combinations

#include <stdio.h>

#define N 20

int count = 0;

void fill(int[], int, int, int);
void insertionSort(int[], int);

int main()
{
    int n, k, i, j, a[N], b[N], l;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    
    for (i = 1; i <= k; i++)
        a[i] = i;

    if(k==n)
    {
        for (l = 1; l <= n; l++)
                printf("%d", a[l]);
            printf("\n");
        count++;
        printf("Total combinations: %d\n", count);

        return 0;
        
    }
    for (j = 1; j <= k; j++)
    {
        a[i] = j;

        fill(a, n, i + 1, k);
        
        //If n-k == 1
        if(i==n)
        {
            for (l = 1; l <= n; l++)
                b[l] = a[l];

            insertionSort(b, n);
        
            for (l = 1; l <= n; l++)
                printf("%d", b[l]);
            printf("\n");
            count++;
        }
    }
    printf("Total combinations: %d\n", count);
}

void fill(int a[], int n, int position, int k)
{
    int i, j, value = 1, b[N];
 
    //Starting from a[position - 1] to prevent repetition of combinations
    for(value = a[position-1]; value <= k && n > position; value++)
    {
        if(value >= a[position-1]) {
            a[position] = value;
            fill(a, n, position + 1, k);
        }
    }
    if (n == position)
    {
        //Starting from a[position - 1] to prevent repetition of combinations
        for (i = a[position-1]; i <= k; i++)
        {
            
            a[position] = i;
            for (j = 1; j <= n; j++)
                b[j] = a[j];

            insertionSort(b, n);

            for (j = 1; j <= n; j++)
                printf("%d", b[j]);
            printf("\n");
            count++;
        }
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 2; i <= n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}