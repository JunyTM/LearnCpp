#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define MAX 100

int G[MAX][MAX], n, source, visited[MAX];

void readData(char *filename, int G[MAX][MAX], int *pn, int *psource)   //pn - số đỉnh
{
    FILE *file = fopen(filename, "r");
    int i, j;
    if (file != NULL)
    {
        fscanf(file, "%d %d", pn, psource);
        for (i = 0; i < *pn; i++)
        {
            for (j = 0; j < *pn; j++)
            {
                fscanf(file, "%d", &G[i][j]);
            }
        }
    }
    fclose(file);
}

void depthFirstSearch(int v)
{
    int w;
    visited[v] = 1;
    printf("%d ", v);
    for (w = 0; w < n; w++)
    {
        if (G[v][w] != 0 && visited[w] == 0)
        {
            depthFirstSearch(w);
        }
    }
}

void breadthFirstSearch(int g[MAX][MAX], int n, int source)
{
    int visited[MAX];
    int i, cur;
    Queue *q = malloc(sizeof(Queue));
    q->ll.size = 0;
    q->ll.head = NULL;

    for (i = 0; i < n; i++)
        visited[i] = 0;
    cur = source;
    visited[cur] = 1;
    enqueue(q, cur);

    while (!isEmptyQueue(q))
    {
        cur = dequeue(q);
        printf("%d ", cur);
        for (i = 0; i < n; i++)
        {
            if (g[cur][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
}

void BFS_Path(int G[MAX][MAX], int n, int startN, int endN)
{
    int visited[MAX];
    int p[MAX];
    int i, j, cur;
    Queue *q = malloc(sizeof(Queue));
    q->ll.size = 0;
    q->ll.head = NULL;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    cur = startN;
    visited[cur] = 1;
    enqueue(q, cur);
    while (!isEmptyQueue(q))
    {
        cur = dequeue(q);
        for (i = 0; i < n; i++)
        {
            if (G[cur][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                p[i] = cur;
                enqueue(q, i);
                if (i == endN)
                {
                    printf("Path = %d", i);
                    j = i;
                    do
                    {
                        j = p[j];
                        printf("<-%d", j);
                    } while (j != startN);
                    return;
                }
            }
        }
    }
}
// --------------------------------- main ---------------------------------------

int main()
{
    int i;
    readData("./BFS_DFS/data.txt", G, &n, &source);

    printf("DFS\n");
    for (i = 0; i < n; i++)
        visited[i] = 0;
    depthFirstSearch(source);

    setbuf(stdout, NULL);
    readData("./BFS_DFS/data.txt", G, &n, &source);
    printf("\nBFS\n");
    breadthFirstSearch(G, n, source);

    printf("\nBFS_Path\n");
    BFS_Path(G, n, source, 4);

    return EXIT_SUCCESS;
}