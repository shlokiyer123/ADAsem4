#include <stdio.h>
#include <limits.h>
#define V 4
int mindist(int dist[],int visited[])
{
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==0 && dist[i]<min)
            min=dist[i],min_index=i;
        
    }
    return min_index;
}

void printMST(int parent[V],int graph[V][V])
{
    printf("Edge \t weight\n");
    for(int i=1;i<V;i++)
        printf("%d - %d\t %d\n",parent[i],i,graph[i][parent[i]]);
}

void prims(int graph[V][V])
{
    int parent[V];
    int dist[V];
    int visited[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=0;
        dist[i]=INT_MAX;
    }
    dist[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count ++)
    {
        int u=mindist(dist,visited);
        visited[u]=1;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && visited[v]==0 && graph[u][v] < dist[v])
            {
                parent[v]=u;
                dist[v]=graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}


int main() {
    int graph[V][V] = { { 0 ,10 ,5 ,0},
                        { 10 ,0 ,15 ,2},
                        { 5 ,15 ,0, 40 },
                        { 0 ,2 ,40 ,0 }, };
    
    prims(graph);
    
    return 0;
}