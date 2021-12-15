#include <stdio.h>
#include <stdlib.h>
#define INFINITY 99999

struct Edge
{ // Mô tả một cạnh có đỉnh đầu u, đỉnh cuối v, trọng số w
     int u;
     int v;
     int w;
};
struct Graph
{ // Mô tả đồ thị có số đỉnh V, số cạnh E, danh sách các cạnh edge
     int V;
     int E;
     struct Edge *edge;
};

void readData(char *filename, struct Graph *g, int *psource)
{
     FILE *file = fopen(filename, "r"); 
     int u, v, w;
     int i = 0;
     if (file != NULL)
     {
          fscanf(file, "%d %d %d", &(g->V), &(g->E), psource);
          g->edge = (struct Edge *)malloc(g->E * sizeof(struct Edge));
          while (!feof(file))
          {
               fscanf(file, "%d %d %d", &u, &v, &w);
               g->edge[i].u = u;
               g->edge[i].v = v;
               g->edge[i].w = w;
               i++;
          }
          fclose(file);
     }
}

void bellmanFord(struct Graph *g, int source)
{
     int i, j, u, v, w;
     int d[g->V];
     int p[g->V];
     for (i = 0; i < g->V; i++)
     {
          d[i] = INFINITY;
          p[i] = 0;
     }
     d[source] = 0;
     for (i = 1; i <= g->V - 1; i++)
     {
          for (j = 0; j < g->E; j++)
          {
               u = g->edge[j].u;
               v = g->edge[j].v;
               w = g->edge[j].w;
               if (d[u] != INFINITY && d[v] > d[u] + w)
               {
                    d[v] = d[u] + w;
                    p[v] = u;
               }
          }
     }
     for (i = 0; i <= g->V - 1; i++)
     {
          if (i != source)
          {
               printf("\nDistance to node %d = %d", i, d[i]);
               printf("\nPath=%d", i);
               j = i;
               do
               {
                    j = p[j];
                    printf("<-%d", j);
               } while (j != source);
          }
     }
}
// ------------------------------------ main ------------------------------------------------------

int main(void)
{
     struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));
     int source;
     readData("./data.txt", g, &source);
     bellmanFord(g, source);
     return 0;
}