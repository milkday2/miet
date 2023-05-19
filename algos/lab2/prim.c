// вариант 15
#include <stdio.h>
#include <stdlib.h>

int minKey(int *key, int *included_nodes, int node_count);
int *prim(int **graph, int node_count);

int main(void) {
  // матрица смежности
  int grapharr[8][8] = {{0, 4, 0, 0, 9, 10, 0, 0}, {4, 0, 1, 0, 3, 0, 2, 0},
                        {0, 1, 0, 1, 0, 1, 0, 7},  {0, 0, 1, 0, 0, 0, 8, 6},
                        {9, 3, 0, 0, 0, 4, 0, 0},  {10, 0, 1, 0, 4, 0, 1, 0},
                        {0, 2, 0, 8, 0, 1, 0, 5},  {0, 0, 7, 6, 0, 0, 5, 0}};
  int **graph = malloc(8 * sizeof(int *));
  for (int i = 0; i < 8; i++) {
    graph[i] = malloc(8 * sizeof(int));
    for (int j = 0; j < 8; j++)
      graph[i][j] = grapharr[i][j];
  }
  int *tree = malloc(8 * sizeof(int));

  tree = prim(graph, 8);
  for (int i = 1; i < 8; i++) {
    printf("%d - %d (%d)\n", tree[i] + 1, i + 1, graph[i][tree[i]]);
  }
  // Результат выполнения:
  // 1 - 2 (4)
  // 2 - 3 (1)
  // 3 - 4 (1)
  // 2 - 5 (3)
  // 3 - 6 (1)
  // 6 - 7 (1)
  // 7 - 8 (5)

  for (int i = 0; i < 8; i++)
    free(graph[i]);
  free(graph);
  free(tree);
  return 0;
}

int minKey(int *key, int *included_nodes, int node_count) {
  int min = 0x7fffffff;
  int min_index;
  for (int n = 0; n < node_count; n++) {
    if (included_nodes[n] == 0 && key[n] < min) {
      min = key[n];
      min_index = n;
    }
  }
  return min_index;
}

int *prim(int **graph, int node_count) {
  int *parent = malloc(node_count * sizeof(int));
  int *included = malloc(node_count * sizeof(int));
  int *key = malloc(node_count * sizeof(int));
  for (int i = 0; i < node_count; i++) {
    key[i] = 0x7fffffff; // max int
    included[i] = 0;
  }
  key[0] = 0;
  parent[0] = 0;

  int v;
  for (int i = 0; i < node_count - 1; i++) {
    v = minKey(key, included, node_count);
    included[v] = 1;
    for (int u = 0; u < node_count; u++) {
      if (graph[v][u] && included[u] == 0 && graph[v][u] < key[u]) {
        key[u] = graph[v][u];
        parent[u] = v;
      }
    }
  }
  return parent;
}
