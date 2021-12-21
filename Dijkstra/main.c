//
//  main.c
//  Dijkstra
//
//  Created by Abdoul Oudouss Diakite on 21/12/2021.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
const int INT_MAX=100000;

// Dijkstra's algorithm
void Dijkstra(int **graph, int n, int start)
{
    // Create a priority queue
    int *dist = (int *)malloc(sizeof(int)*n);
    int *prev = (int *)malloc(sizeof(int)*n);
    int *visited = (int *)malloc(sizeof(int)*n);
    int i, u, v, w;//u is the current vertex, v is the adjacent vertex, w is the weight of the edge
    // Initialize the distance array to infinity
    // Initialize the previous array to -1
    // Initialize the visited array to 0
    for(i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = 0;
    }
    dist[start] = 0;
    for(i=0; i<n; i++)
    {
        u = -1;
        for(v=0; v<n; v++)
        {
            if(!visited[v] && (u==-1 || dist[v]<dist[u]))
                u = v;
        }
        visited[u] = 1;
        for(v=0; v<n; v++)
        {
            if(!visited[v] && graph[u][v]!=0 && dist[u]+graph[u][v]<dist[v])
            {
                dist[v] = dist[u]+graph[u][v];
                prev[v] = u;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        if(i!=start)
        {
            printf("%d ", dist[i]);
            w = i;
            while(prev[w]!=-1)
            {
                printf(" The path is %d", prev[w]);
                w = prev[w];
            }
            printf("\n");
        }
    }
}
// Main function to test the Dijkstra's algorithm
int main()
{
    int n, i, j,start, **graph;
    // Enter the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Create a graph
    graph = (int **)malloc(sizeof(int *)*n);
    for (i=0; i<n; i++)
        graph[i] = (int *)malloc(sizeof(int)*n);
    // Enter the adjacency matrix
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter the weight of edge %d-%d: ", i+1, j+1);
            scanf("%d", &graph[i][j]);
        }
    }
    // Enter the starting vertex
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    Dijkstra(graph, n, start);
    return 0;
}
