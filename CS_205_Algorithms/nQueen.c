//Code for the Chess Queen's Problem

//Name: Devansh Maurya
//Roll No.: B16CS024
//Algorithm: N Queen Problem

#include<stdio.h>
#include<stdbool.h>

#define S 10

int queenPosition[S][S];

void placeChessQueen(int, int);
void printPositions(int);
bool positionIsAvailable(int, int, int);

int main()
{
	int totalQueens, i, j;
	
	printf("Enter the number of queens: ");
	scanf("%d", &totalQueens);

    for(i=1; i<=totalQueens; i++)
        for(j=0; j<=totalQueens; j++)
            queenPosition[i][j]= 0;

    if(totalQueens<=3)
    {
        printf("\nSolution does not exist !\n\n");
        return 0;
    }
    else
        placeChessQueen(totalQueens, 1);

	return 0;
}


void placeChessQueen(int totalQueens, int queenNo)
{
	int column;
    
    //If last queen has been placed, then print the solution
    if(queenNo== totalQueens+1)                             
    {
        printPositions(totalQueens);
    }
    else
		for(column=1; column<= totalQueens; column++)
		if(positionIsAvailable(totalQueens, queenNo, column))
		{
			//Place the queen
			queenPosition[queenNo][column]= 1;              

			//Try to place the next queen
			placeChessQueen(totalQueens, queenNo+1);        

			//Backtrack to check other solutions
			queenPosition[queenNo][column]= 0;             
		}
}


bool positionIsAvailable(int totalQueens, int queenNo, int column)
{
    int queen, itsColumn;

    //Check if new queen has been placed in an attacking column
    for(queen=1; queen< queenNo; queen++)
        if(queenPosition[queen][column])
            return false;
    
    //Check if new queen has been placed in an attacking top right diagonal
    for(queen= queenNo-1, itsColumn= column+1; queen>= 1 && itsColumn<=totalQueens; queen--, itsColumn++ )
        if(queenPosition[queen][itsColumn])
            return false;
    //Check if new queen has been placed in an attacking top left diagonal
    for(queen= queenNo-1, itsColumn= column-1; queen>= 1 && itsColumn>=1; queen--, itsColumn-- )
        if(queenPosition[queen][itsColumn])
            return false;
    
    return true;
}

//Print the solution
void printPositions(int totalQueens)
{                     
    int k, j;
    static int solutionNo= 1;

    printf("\n\nSolution : %d\n\n", solutionNo++);
    for(k=1; k<=totalQueens; k++)
    {
        for(j=1; j<=totalQueens; j++)
        {
            printf("%d ", queenPosition[k][j]);
        }
        printf("\n");
    }
}
