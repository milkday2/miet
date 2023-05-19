#include <stdio.h>
#include <stdlib.h>

#define NODES 8

void dijkstra(int **graph, int *distance, int *parent, int nodes);
int minDist(int *dist, int *included, int nodes);

int main(void) {
  int graph_arr[8][8] = {
      {0, 18, 0, 4, 0, 0, 9, 22}, {18, 0, 1, 0, 3, 0, 0, 1},
      {0, 1, 0, 0, 13, 0, 0, 0},  {4, 0, 0, 0, 0, 5, 7, 0},
      {0, 3, 13, 0, 0, 0, 2, 9},  {0, 0, 0, 5, 0, 0, 5, 0},
      {9, 0, 0, 7, 2, 5, 0, 10},  {22, 1, 0, 0, 9, 0, 10, 0}};
  int **graph = malloc(NODES * sizeof(int *));
  for (int i = 0; i < NODES; i++) {
    graph[i] = malloc(NODES * sizeof(int));
    for (int j = 0; j < NODES; j++)
      graph[i][j] = graph_arr[i][j];
  }
  int *distance = malloc(NODES * sizeof(int));
  int *parent = malloc(NODES * sizeof(int));
  dijkstra(graph, distance, parent, NODES);
  for (int i = 0; i < NODES; i++)
    printf("%d ", distance[i]);
  printf("\n");
  for (int i = 0; i < NODES; i++) {
    printf("%d - %d\n", parent[i], i);
  }
  // Результат (источник - 1-я вершина):
  // кратчайшие пути:
  // 0 14 15 4 11 9 9 15
  // дерево кратч. путей:
  // 0 - 0
  // 4 - 1
  // 1 - 2
  // 0 - 3
  // 6 - 4
  // 3 - 5
  // 0 - 6
  // 1 - 7
  return 0;
}

void dijkstra(int **graph, int *distance, int *parent, int nodes) {
  int *included = malloc(nodes * sizeof(int));
  for (int i = 0; i < nodes; i++) {
    included[i] = 0;
    distance[i] = 0x7fffffff;
  }
  distance[0] = 0;
  parent[0] = 0;
  int v;
  for (int i = 0; i < nodes - 1; i++) {
    v = minDist(distance, included, nodes);
    included[v] = 1;
    for (int u = 0; u < nodes; u++) {
      if (!included[u] && graph[v][u] &&
          distance[v] + graph[v][u] < distance[u]) {
        distance[u] = distance[v] + graph[v][u];
        parent[u] = v;
      }
    }
  }
}

int minDist(int *dist, int *included, int nodes) {
  int min = 0x7fffffff;
  int min_index;
  for (int i = 0; i < nodes; i++) {
    if (!included[i] && dist[i] < min) {
      min = dist[i];
      min_index = i;
    }
  }
  return min_index;
}
