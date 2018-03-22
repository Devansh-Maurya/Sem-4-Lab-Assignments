#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define V 10

void dijkstra(int (*)[V], int);
int findMinVertex(int [V], bool* , int);

int main(void)
{
    int edges[V][V], i, j, n;

    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix:\n");
    for(i= 0; i<n; i++)
        for(j= 0; j<n; j++)
            scanf("%d",&edges[i][j]);
    
    printf("The adjacency matrix you entered is:\n");
    for(i= 0; i<n; i++)
    {
        for(j= 0; j<n; j++)
            printf("%d ",edges[i][j]);
        printf("\n");
    }

    dijkstra(edges, n);
}

void dijkstra(int edges[V][V], int n)
{
    bool visited[V];
    int distance[V], predecessor[V], i, j, minVertex, dis;

    for(i=0; i<n; i++)
    {
        distance[i]= INT_MAX;
        visited[i]= false;
    }

    distance[0]= 0;

    for(i=0; i<n-1; i++)
    {
        minVertex= findMinVertex(distance, visited, n);
        visited[minVertex]= true;

        for(j=0; j<n; j++)
        {
            if(edges[minVertex][j] && !visited[j])
            {
                dis= distance[minVertex] + edges[minVertex][j];

                if(!visited[j] && dis< distance[j])
                {
                    distance[j]= dis;
                    predecessor[j]= minVertex;
                }
            }
        }
    }

    printf("Vertices with shortest paths: ");
    for(i=0; i<n; i++)
    {
        if(distance[i]!= INT_MAX)
            printf("%d %d\n", i, distance[i]);
        else
            printf("%d Path does not exist\n", i);
    }
    
    printf("Paths:\n");
    for(i=1; i<n; i++)
    {
        printf("Path to reach %d: ", i);
        j=i;

        printf("%d<-", j);
        if(distance[i]!=INT_MAX);
        {
            while(predecessor[j])
            {
                printf("%d<-", predecessor[j]);
                j= predecessor[j];
            }
            printf("0\n\n");
        }

    }

}

int findMinVertex(int distance[V], bool visited[V], int n)
{
    int i, minVertex;

    minVertex= -1;

    for(i=0 ; i<n; i++)
        if(!visited[i] && (minVertex== -1 || distance[i]< distance[minVertex]))
            minVertex= i;
        
    return minVertex;
}