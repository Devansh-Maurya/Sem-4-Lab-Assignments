//the final working code for the Chess Queen's Problem
//Still need to print only the correct answer

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
        for(k=1; k<=n; k++)             //Initialize the matrix
            for(j=1; j<=n; j++)
		    queenPosition[k][j]= 9;

        blockPositions(n, 1, i);        //Block positions relative to first queen
        
        queenPosition[1][i]= 1;         //Mark position of first queen

		placeChessQueen(n, 2);
	}
	
	return 0;
}

void placeChessQueen(int n, int queenNo)
{
	int j, k;
    
    printf("Queen positions:\n\n");     //Print the solution
                for(k=1; k<=n; k++)
                {
                    for(j=1; j<=n; j++)
                        printf("%d ", queenPosition[k][j]);
                    printf("\n");
                }
                
	if(queenNo<= n)
		for(j=1; j<=n; j++)
			if(!queenPosition[queenNo][j])          //Condition in which not to call the function
			{
				continue;
			}
			else
			{
                blockPositions(n, queenNo, j);      //Block positions relative to queen queenNo

                queenPosition[queenNo][j]= queenNo; //Mark position of queenNo queen

                

				placeChessQueen(n, ++queenNo);      //Recursively call the function with the next queen
			}
}

void blockPositions(int n, int queenNo, int j)      //Blocking the positions
{
    int i, k;

    for(i=1; i<=n; i++)                             //Block the corresponding row and column
                queenPosition[queenNo][i]= queenPosition[i][j]= 0;

    for(k=queenNo, i=j; k<=n && i<=n; k++, i++)     //Blocking the diagonals
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