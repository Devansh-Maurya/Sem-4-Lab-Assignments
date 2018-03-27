//Floyd Warshall Algorithm

#include <stdio.h>
#include <limits.h>

#define S 10
#define NO_PATH 0

struct presentPreviousMatrix
{
    int present;
    int previous;
};

typedef struct presentPreviousMatrix presentPreviousMatrix;

void floydWarshall (int [S][S], int);
void inputMatrix (int [S][S], int);
void printMatrix (int [S][S], int);
void initializePathMatrix (int [S][S], int, presentPreviousMatrix [S][S]);
void initializeDistanceMatrix (int [S][S], int, presentPreviousMatrix [S][S]);
void printPresentPrevoiusMatrix (presentPreviousMatrix [S][S], int);
void calculateAllPairShortestPath (presentPreviousMatrix [S][S], presentPreviousMatrix [S][S], int);
void updatePreviousByPresent (presentPreviousMatrix*);
void printAllPairShortestPathsWithDistances (presentPreviousMatrix [S][S], presentPreviousMatrix [S][S], int);

int main()
{
    int G[S][S], n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    printf("Enter '99' if no edge between the nodes is present)\n(Enter 0 if two nodes of an edge are same)\n\n");
    inputMatrix(G, n);

    floydWarshall(G, n);

    return 0;

}


void floydWarshall(int G[S][S], int n)
{
    presentPreviousMatrix distance[S][S], path[S][S];

    printf("\nYou entered following adjacency matrix:\n");
    printMatrix(G, n);

    initializeDistanceMatrix(G, n, distance);

    initializePathMatrix(G, n, path);

    calculateAllPairShortestPath(distance, path, n);

    printf("\nThe all pair shortest path distance matrix is: \n");
    printPresentPrevoiusMatrix(distance, n);

    printf("\nThe all pair shortest path path matrix is: \n");
    printPresentPrevoiusMatrix(path, n);

    printf("\nThe shortest paths are:\n\n");
    printAllPairShortestPathsWithDistances(distance, path, n);

}


void inputMatrix(int m[S][S], int n)
{
    int i, j;

    for(i=0; i <n ; i++)
        for(j=0; j < n; j++)
        {
            scanf("%d", &m[i][j]);
        }
}


void calculateAllPairShortestPath(presentPreviousMatrix distance[S][S], presentPreviousMatrix path[S][S], int n)
{
    int i, j, k;

    for(k = 0; k < n; k++)
        {
            for(i = 0; i < n; i++)
            {
                for(j = 0; j < n; j++)
                {
                    if(distance[i][j].previous <= ( distance[i][k].previous + distance[k][j].previous ))
                    {
                        distance[i][j].present = distance[i][j].previous;
                        path[i][j].present = path[i][j].previous;
                    }
                    else
                    {
                        distance[i][j].present = distance[i][k].previous + distance[k][j].previous;
                        path[i][j].present = path[k][j].previous;
                    }
                    
                    updatePreviousByPresent(&distance[i][j]);
                    updatePreviousByPresent(&path[i][j]);
                } 
            }
        }
        
}

void printMatrix(int m[S][S], int n)
{
    int i, j;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

void initializePathMatrix(int G[S][S], int n, presentPreviousMatrix path[S][S])
{
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(G[i][j] == 0 || G[i][j] == 99)
                path[i][j].previous = NO_PATH;
            else
                path[i][j].previous = i+1;

}


void initializeDistanceMatrix(int G[S][S], int n, presentPreviousMatrix distance[S][S])
{
    int i, j;

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            distance[i][j].previous= G[i][j];
            
}


void printPresentPrevoiusMatrix(presentPreviousMatrix m[S][S], int n)
{
    int i, j;

    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
        {
            if(m[i][j].present == 99)
                printf("\tinf");
            else
                printf("\t%d ", m[i][j].present);
        }
        printf("\n");
    }

    printf("\n\n");
}


void updatePreviousByPresent(presentPreviousMatrix* element)
{
    (*element).previous = (*element).present;
}

void printAllPairShortestPathsWithDistances(presentPreviousMatrix distance[S][S], presentPreviousMatrix path[S][S], int n)
{
    int i, j, pathPrinter, current;

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            pathPrinter= path[i][j].present;
            current= i+1;

            printf("Path (%d,%d) : ", i+1, j+1);

            if(pathPrinter == 0)
                if( i != j)
                    printf("No path exists from %d to %d\n", i+1, j+1);
                else
                    printf("Same nodes\n");
            else
            {
                printf("%d -> ", i+1);
                while(pathPrinter != current)
                {
                    printf("%d -> ", pathPrinter);
                    current= pathPrinter;
                    pathPrinter= path[pathPrinter-1][j].present;
                }
                printf("%d\n", j+1);
            }
        }
        printf("\n");
    }
}