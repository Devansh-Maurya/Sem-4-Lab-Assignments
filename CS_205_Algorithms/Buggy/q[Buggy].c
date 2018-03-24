//the final working code for the Chess Queen's Problem
//Still need to print only the correct answer

#include<stdio.h>
#include<stdlib.h>

#define S 10
#define true 1
#define false 0

typedef int bool;

int queenPosition[S];

void placeChessQueen(int, int);
bool positionIsAvailable(int, int, int);
void printPositions(int);

int count=0;

int main()
{
	int n, i;
	
	printf("Enter the number of queens: ");
	scanf("%d", &n);

    for(i=1; i<=n; i++)
        queenPosition[S]= 0;

	for(i=1; i<=n; i++)
	{
        queenPosition[1]= i;

		placeChessQueen(n, 2);
	}
	
    printf("Total solutions= %d", count);

	return 0;
}

void placeChessQueen(int n, int queenNo)
{
	int i, column;

    if(queenNo=n+1)
                    printPositions(n);    
	if(queenNo<= n)
    {       
        for(column=1; column<=n; column++)
			if(positionIsAvailable(n, queenNo, column))          //Condition in which to call the function
			{
                queenPosition[queenNo]= column;
            }

                
                else
				placeChessQueen(n, ++queenNo);      //Recursively call the function with the next queen
			}
    }


bool positionIsAvailable(int totalQueens, int queenNo, int column)
{
    int queen;

    for(queen=1; queen<queenNo; queen++)
        if((queenPosition[queen]== column) || abs(queenPosition[queen]-column)==abs(queen-queenNo))
            return false;
    return true;
}

void printPositions(int totalQueens)
{
    int i;

    for(i=1; i<=totalQueens; i++)
    {
       printf("%d ", queenPosition[i]);
    }
    count++;
    printf("\n");
}