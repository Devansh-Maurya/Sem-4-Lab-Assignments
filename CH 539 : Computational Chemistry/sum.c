#include<stdio.h>

int main()
{
	int n, i, sum= 0;

	scanf("%d",&n);

	for(i=1; i<=n; i++)
	{
		sum+= i;
		printf("%d\n", i);
	}

	printf("\nThe sum of numbers from 1 to %d is %d\n", n, sum);

	return 0;
}

