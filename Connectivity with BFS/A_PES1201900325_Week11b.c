#include<stdio.h>
#include "bfs.h"

int check_path(int **graph, int n, int v, int u)
{
    int visited[n];
    int queue[n];
    int front=0,rear=-1;
    for (int m=0;m<n;m++)
    {
        visited[m]=0;
    }
    
    queue[++rear] = v;
    visited[v]=1;
    
    while (front<=rear)
    {
        int x=queue[front++];
        if (x==u)
        {
            return 1;
        }
        for (int i=0;i<n;i++)
        {
            if (graph[x][i] && !visited[i])
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
    return 0;
}
    

