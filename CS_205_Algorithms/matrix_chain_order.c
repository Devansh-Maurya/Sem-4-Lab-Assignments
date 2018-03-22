#include<stdio.h>
#include<limits.h>

#define S 10

void matrix_chain_order(int [], int);
void print_optimal_parens(int (*)[S], int, int);

int main()
{
    int p[S]; int n, i;

    printf("How many matrices? ");
    scanf("%d",&n);

    printf("Enter the dimensions consecutively: ");
    for(i=0; i<=n; i++)
    {
        scanf("%d",&p[i]);
    }

    matrix_chain_order(p, n);
}

void matrix_chain_order( int p[], int n)
{
    int m[S][S], i, s[S][S], l, j, k, q;

    for(i=1; i<=n; i++)
    {
        m[i][i]= 0;
    }

    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {            
            j= i+l-1;
            m[i][j]= INT_MAX;

            for(k=i; k<j; k++)
            {
                q= m[i][k]+ m[k+1][j]+ p[i-1]*p[k]*p[j];
                
                if(q< m[i][j])
                {
                    m[i][j]= q;
                    s[i][j]= k;
                }
            }
        }
    }

    printf("Solution: ");
    print_optimal_parens(s, 1, n);
    printf("\n");
    
    printf("\nThe matrix containing total products\n\n");
    for(i=n; i>=1; i--)
    {
        for(j=n; j>=i; j--)
            printf("%d ", m[i][j]);
        printf("\n");
    }

    printf("\n\nThe matrix containing total value of k\n\n");
    for(i=n-1; i>=1; i--)
    {
        for(j=n; j>=i+1; j--)
            printf("%d ", s[i][j]);
        printf("\n");
    }

}

void print_optimal_parens(int s[S][S], int i, int j)
{
    if(i==j)
        printf("A%d ", i);
    else
    {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j]+1, j);
        printf(")");
    }
}