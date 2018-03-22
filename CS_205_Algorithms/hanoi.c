#include<stdio.h>

int tower(int, char, char, char);

int main()
{
    int n;
    printf("Enter the number of rings: ");
    scanf("%d",&n);

    printf("Total steps: %d\n", tower(n, 'A', 'B', 'C'));

    return 0;
}

int tower(int n, char beg, char aux, char end)
{
    static int count;

    if(n==0)
    {
        printf("No rings\n");
        return 0;
    }
    else if(n==1)
    {  
        printf("Move disc 1 from %c to %c\n",beg, end);
        count++;
    }
    else
    {
        tower(n-1, beg, end, aux);
        printf("Move disc %d from %c to %c\n",n, beg, end);
        count++;
        tower(n-1, aux, beg, end);
    }

    return count;

}