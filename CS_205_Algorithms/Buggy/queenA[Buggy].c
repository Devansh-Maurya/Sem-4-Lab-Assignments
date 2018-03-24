//the final working code for the Chess Queen's Problem
//Still need to print only the correct answer

#include<stdio.h>

#define S 10

struct chessBoard
{
    int value;
    int changedBy;
} 
queenPosition[S][S];

void placeChessQueen(int, int);
void blockPositions(int, int, int);

static int canNotKeep=0;

int main()
{
	int n, i, j, k;
	
	printf("Enter the number of queens: ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
	{
        for(k=1; k<=n; k++)             //Initialize the matrix
            for(j=1; j<=n; j++)
            {
		        queenPosition[k][j].value= 9;
                queenPosition[k][j].changedBy= 0;
            }

        blockPositions(n, 1, i);        //Block positions relative to first queen
        
        queenPosition[1][i].value= 1;         //Mark position of first queen

		placeChessQueen(n, 2);
	}
	
	return 0;
}

void placeChessQueen(int n, int queenNo)
{
	int j, k, i, queen;
   
    printf("Queen positions:\n\n");     //Print the solution
    for(k=1; k<=n; k++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", queenPosition[k][j].value);
        printf("\n");
    }
                
	if(queenNo<= n)
    {
        canNotKeep= 0;
		for(j=1; j<=n; j++)
        {   
			if(!queenPosition[queenNo][j].value)          //Condition in which not to call the function
            {
                canNotKeep++;
                printf("For queen %d, canNotKeep= %d\n", queenNo, canNotKeep);
				continue;
			}
			else
			{
                canNotKeep=0;

                blockPositions(n, queenNo, j);      //Block positions relative to queen queenNo

                queenPosition[queenNo][j].value= queenNo; //Mark position of queenNo queen

				placeChessQueen(n, queenNo+1);     //Recursively call the function with the next queen
			
                for(i=queenNo; i<=n; i++)
                    for(k=1; k<=n; k++)
                    {
                        if((queenPosition[queenNo][k].value==0 || queenPosition[queenNo][k].value==queenNo) && queenPosition[queenNo][k].changedBy==queenNo)
                        {  
                            queenPosition[queenNo][k].value=9;
                            queenPosition[queenNo][k].changedBy=0;
                        }
                    }            
            }
        }
    }
}

void blockPositions(int n, int queenNo, int j)      //Blocking the positions
{
    int i, k;

    for(i=1; i<=n; i++)
    {                             
        queenPosition[queenNo][i].value= queenPosition[i][j].value= 0;                  //Block the corresponding row and column
        queenPosition[queenNo][i].changedBy= queenPosition[i][j].changedBy= queenNo;
    }

    for(k=queenNo, i=j; k<=n && i<=n; k++, i++)     //Blocking the diagonals
        if(queenPosition[k][i].value>queenNo)
        {
            queenPosition[k][i].value= 0;
            queenPosition[k][i].changedBy= queenNo;
        }
                                    

    for(k=queenNo, i=j; k<=n && i>=1; k++, i--)
        if(queenPosition[k][i].value>queenNo)
        {
            queenPosition[k][i].value= 0;
            queenPosition[k][i].changedBy= queenNo;
        }

    for(k=queenNo, i=j; k>=1 && i<=n; k--, i++)
        if(queenPosition[k][i].value>queenNo)
        {
                queenPosition[k][i].value= 0;
                queenPosition[k][i].changedBy= queenNo;
        }
    
    for(k=queenNo, i=j; k>=1 && i>=1; k--, i--)
        if(queenPosition[k][i].value>queenNo)
        {
            queenPosition[k][i].value= 0;
            queenPosition[k][i].changedBy= queenNo;
        }
}