//For final solution, see queenFinal.c

#include<stdio.h>

#define S 10

int queenPosition[S][S];

void placeChessQueen(int, int);
void blockPositions(int, int, int);

int main()
{
	int n, i, j, k;
	
	printf("Enter the number of queens: ");
	scanf("%d", &n);
		
	for(i=1; i<=n; i++)
	{
        for(k=1; k<=n; k++)
            for(j=1; j<=n; j++)
		    queenPosition[k][j]= 9;

        printf("initial Queen positions:\n\n");
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
                printf("%d ", queenPosition[k][j]);
            printf("\n");
        }

        for(j=1; j<=n; j++)
                queenPosition[1][j]= (queenPosition[j][i]= 0);

        printf("Queen positions:\n\n");
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
                printf("%d ", queenPosition[k][j]);
            printf("\n");
        }

        for(k=1, j=i; k<=n && j<=n; k++, j++)
            queenPosition[k][j]= 0;

        printf("Queen positions:\n\n");
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
                printf("%d ", queenPosition[k][j]);
            printf("\n");
        }
        
        for(k=1, j=i; k<=n && j>=1; k++, j--)
            queenPosition[k][j]= 0;
        
        queenPosition[1][i]= 1;

        printf("Queen positions:\n\n");
        for(k=1; k<=n; k++)
        {
            for(j=1; j<=n; j++)
                printf("%d ", queenPosition[k][j]);
            printf("\n");
        }

		placeChessQueen(n, 2);

        printf("Value of i=%d\n", i);
        
	}
	
	return 0;
}

void placeChessQueen(int n, int queenNo)
{
	int j, k;
	
    printf("Queen positions:\n\n");
    for(k=1; k<=n; k++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", queenPosition[k][j]);
        printf("\n");
    }
    
	if(queenNo<= n)
		for(j=1; j<=n; j++)
			//Conditions in which not to call the function
			if(!queenPosition[queenNo][j])
			{
				continue;
			}
			else
			{
                blockPositions(n, queenNo, j);

                queenPosition[queenNo][j]= queenNo;

                printf("Queen positions:\n\n");
                for(k=1; k<=n; k++)
                {
                    for(j=1; j<=n; j++)
                        printf("%d ", queenPosition[k][j]);
                    printf("\n");
                }
                
                
				placeChessQueen(n, ++queenNo);
			}
}

void blockPositions(int n, int queenNo, int j)
{
    int i, k;

    for(i=1; i<=n; i++)
                queenPosition[queenNo][i]= queenPosition[i][j]= 0;

    for(k=queenNo, i=j; k<=n && i<=n; k++, i++)
        if(queenPosition[k][i]>queenNo)
            queenPosition[k][i]= 0;

    for(k=queenNo, i=j; k<=n && i>=1; k++, i--)
        if(queenPosition[k][i]>queenNo)
            queenPosition[k][i]= 0;

    for(k=queenNo, i=j; k>=1 && i<=n; k--, i++)
        if(queenPosition[k][i]>queenNo)
            queenPosition[k][i]= 0;
    
    for(k=queenNo, i=j; k>=1 && i>=1; k--, i--)
        if(queenPosition[k][i]>queenNo)
            queenPosition[k][i]= 0;
}