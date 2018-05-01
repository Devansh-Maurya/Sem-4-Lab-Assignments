#include<stdio.h>

#define S 10

int partition(int *, int, int);
int ksmallest(int *, int, int);

int main()
{
    int n, i, a[S], k;

    printf("Enter the size: ");
    scanf("%d", &n);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter the elements: ");
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    
    printf("%d smallest element: %d\n", k, ksmallest(a, n, k-1));

    return 0;
}

int ksmallest(int *a, int n, int k)
{
    int low, up, pivot, i;

    low = 0;
    up = n-1;

    while(low<=up)
    {
        pivot = partition(a, low, up);

        if(pivot == k)
            return a[pivot];
        else if(pivot < k)
            low = pivot + 1;
        else
            up = pivot - 1;
    }
}

int partition(int *a, int beg, int end)
{
    int left, right, loc, temp, flag;

    loc = beg;
    left = beg;
    right = end;

    while(flag)
    {
        while(a[loc] < a[right] && loc != right)
            right--;
        if(loc == right)
            flag = 0;
        if(a[loc] > a[right])
        {
            temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;

            loc = right;
        }
    }

    if(flag)
    {
        while(a[loc] > a[left] && loc != left)
            left--;
        if(loc == left)
            flag = 0;
        if(a[loc] > a[left])
        {
            temp = a[loc];
            a[loc] = a[left];
            a[left] = temp;

            loc = left;
        }
    }

    return loc;
}