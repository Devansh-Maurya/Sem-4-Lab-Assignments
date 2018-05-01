#include<stdio.h>

#define S 10
#define E 100

struct weightedEdge
{
    int source;
    int destination;
    int weight;
};

typedef struct weightedEdge weightedEdge;

void edge_weight_based_merge_sort(weightedEdge *, int, int);
void merge(weightedEdge *, int, int, int);
void kruskal(int [][S], int);
int findParent(int, int *);
void insertion(weightedEdge *, int);

int main()
{
    int i, j, n, G[S][S];
    weightedEdge edge[E];

    printf("Enter the number of node: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: ");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    kruskal(G, n);

}

void kruskal(int G[][S], int n)
{
    int edgeCount = 1, i, j, parent[S], sourceParent, destinationParent, totalWeight = 0;
    weightedEdge edge[E], currentedge, output[S];

    for(i=1; i<=n; i++)
    {
        parent[i] = i;
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i!=j)
            {
                edge[edgeCount].source = i;
                edge[edgeCount].destination = j;
                edge[edgeCount].weight = G[i][j];
                edgeCount++;
            }
        }
    }                                                                                                         

    insertion(edge, edgeCount);}

    for(edgeCount=1, i=1; edgeCount != n; i++)
    {
        currentedge = edge[i];

        sourceParent = findParent(currentedge.source, parent);
        destinationParent = findParent(currentedge.destination, parent);

        if(sourceParent != destinationParent)
        {
            output[edgeCount++] = currentedge;
            parent[sourceParent] = destinationParent;
        }
    }

    printf("Edges in the MST:\n");
    for(i=1; i<edgeCount; i++)
    {
        printf("(%d, %d) : %d\n", output[i].source, output[i].destination, output[i].weight);
        totalWeight += output[i].weight;
    }
    printf("\nTotal weight of MST: %d\n", totalWeight);
}

int findParent(int vertex, int *parent)
{
    if(parent[vertex] == vertex)
        return vertex;
    else
        return findParent(parent[vertex], parent);
}

void insertion(weightedEdge *a, int n)
{
    int i, j;
    weightedEdge k;

    for(i=2; i<=n; i++)
    {
        k = a[i];

        for(j = i-1; (j>=1) && (a[j].weight > k.weight); j--)
        {
           a[j+1] = a[j];
        }
        a[j+1] = k;
    }
}
