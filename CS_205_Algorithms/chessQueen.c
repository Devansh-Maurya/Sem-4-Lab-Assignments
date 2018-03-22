#include<stdio.h>

#define S 10

int queen[S];

int main()
{
	int n, sol, i;
	
	printf("Enter the number of queens: ");
	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
		queen[i]= i;
		
	for(i=1; i<=n; i++)
	{
		printf("1 queen has been placed at position %d\n", i);
		placeChessQueen(i, n, 2);
	}
			
	return 0;
}

placeChessQueen(int i, int n, int queenNo)
{
	int j;
	
	if(queenNo<= n)
		for(j=1; j<=n; j++)
			//Conditions in which not to call the function
			if((i==1 && j==i)||(i==n && j==i) || (j==i+1) || (j==i-1))
			{
				printf("%d queen can't be placed at %d\n", queenNo, j);
				continue;
			}
			else
			{
				if(queenNo==n)
				{
					printf("Last queen can be palced at %d\n\n", j);
					return 1;
				}
				else
				{
					printf("%d queen can be placed at %d\n", queenNo, j);	
					return placeChessQueen(j, n, ++queenNo);
				}
			}
}
	
	
		
