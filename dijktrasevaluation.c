// Dijkstra's Algorithm in C

#include <stdio.h>
#define INFINITY 9999
#define MAX 10



void Dijkstra(int Gph[MAX][MAX], int n, int start) {
  int cost[MAX][MAX], dist[MAX], pred[MAX];
  int visited[MAX], count, mindist, nextnode, i, j;


  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Gph[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = Gph[i][j];

  for (i = 0; i < n; i++) {
    dist[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  dist[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindist = INFINITY;

    for (i = 0; i < n; i++)
      if (dist[i] < mindist && !visited[i]) {
        mindist = dist[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindist + cost[nextnode][i] < dist[i]) {
          dist[i] = mindist + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nSOURCE DISTANCE02 %d: %d", i, dist[i]);
    }
}
int main() {
  int Gph[MAX][MAX], i, j, n, u;
  n = 7;

 

  u = 0;
  
printf("**********************\n");
printf("ENTER THE NUMBER OF VERTICES\n");
scanf("%d",&u);
printf("**********************\n");
printf("ENTER THE WEIGHTED GRAPH MATRIX\n");
for(int i=0; i<u; i++)
{
    for (int j = 0; j < u; j++)
{
     printf("%d->%d\t",i+1,j+1);
     scanf("%d",&Gph[i][j]);
}

   
}
Dijkstra(Gph, n, u);
  return 0;
}