#include <stdio.h>

#define S 10

struct floyd
{
    int present;
    int previous;
};

typedef struct floyd floyd;

void inputMatrix(int [][S], int);
void floydWarshall(int [][S], int);
void printAllPairShortestPath(floyd [][S], floyd [][S], int, int, int);

int main()
{
    int G[S][S], n, i, j;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    printf("Enter '99' if no edge between the nodes is present)\n(Enter 0 if two nodes of an edge are same)\n\n");
    inputMatrix(G, n);

    floydWarshall(G, n);

    return 0;

}

void inputMatrix(int m[S][S], int n)
{
    int i, j;

    for(i=1; i <=n ; i++)
        for(j=1; j <= n; j++)
        {
            scanf("%d", &m[i][j]);
        }
}

void floydWarshall(int G[][S], int n)
{
    int i, j, k;
    floyd w[S][S], path[S][S];

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            if(G[i][j] == 0 || G[i][j] == 99)
                path[i][j].previous = 0;
            else
                path[i][j].previous = i;
        }
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            w[i][j].previous = G[i][j];
        }
    }

    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(w[i][j].previous <= (w[i][k].previous + w[k][j].previous))
                {
                    w[i][j].present = w[i][j].previous;
                    path[i][j].present = path[i][j].previous;
                }
                else
                {
                    w[i][j].present = w[i][k].previous + w[k][j].previous;
                    path[i][j].present = path[k][j].previous;
                }

                path[i][j].previous = path[i][j].present;
                w[i][j].previous = w[i][j].present;
            }
        }
    }

    printf("\n");
    printf("Distance matrix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", w[i][j].present);
        printf("\n");
    }
    printf("\n");

    printf("Path matrix:\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            printf("%d ", path[i][j].present);
        printf("\n");
    }
    printf("\n");

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            printf("Path from %d to %d: ", i, j);
            printAllPairShortestPath(w, path, n, i, j);
            printf("\b");
            printf("\n");
        }
        printf("\n");
    }
}

void printAllPairShortestPath(floyd w[][S], floyd path[][S], int n, int i, int j)
{
    if(i == j)
        printf("%d, ", i);
    else
    {
        if(path[i][j].present == 0)
            printf("No path from %d to %d", i, j);
        else
        {
            printAllPairShortestPath(w, path, n,  i, path[i][j].present);
            printf("%d, ", j);
        }
    }
}