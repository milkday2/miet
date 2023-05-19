// метод динамического программирования, вар.3
#include <stdio.h>
#include <stdlib.h>

#define NODES 7

struct f_tuple {
  int min; // значение f[j]
  int min_index; // номер предыдущей вершины в мин. пути до j
  int set; // флаг: f[j] известно/не известно
};
struct f_tuple *f_tuple_array(int nodes);

void F(int node, int **graph, struct f_tuple *f, int nodes);
void print_path(struct f_tuple *f, int node);

int main(void) {
  int graph_arr[NODES][NODES] = {
      {0, 1, 0, 8, 25, 0, 20}, {0, 0, 2, 0, 0, 0, 15}, {0, 0, 0, 0, 0, 3, 0},
      {0, 0, 0, 0, 9, 0, 0},   {0, 0, 0, 0, 0, 0, 6},  {0, 0, 0, 0, 0, 0, 4},
      {0, 0, 0, 0, 0, 0, 0}};
  int **graph = malloc(NODES * sizeof(int *));
  for (int i = 0; i < NODES; i++) {
    graph[i] = malloc(NODES * sizeof(int));
    for (int j = 0; j < NODES; j++)
      graph[i][j] = graph_arr[i][j];
  }
  struct f_tuple *f = f_tuple_array(NODES);

  F(NODES - 1, graph, f, NODES);
  for (int i = 0; i < NODES; i++)
    printf("%d ", f[i].min);
  printf("\n");
  print_path(f, NODES - 1);
  // Результат:
  // мин. расстояния до каждой вершины от 0ой:
  // 0 1 3 8 17 6 10
  // мин. путь от 6ой вершины до 0ой:
  // 5 - 2 - 1 - 0

  for (int i = 0; i < NODES; i++)
    free(graph[i]);
  free(graph);
  free(f);
  return 0;
}

void F(int node, int **graph, struct f_tuple *f, int nodes) {
  if (!node) {
    f[node].min = 0;
    f[node].min_index = 0;
    f[node].set = 1;
    return;
  }
  f[node].min = 0x7fffffff;
  for (int i = 0; i < nodes; i++) {
    if (graph[i][node]) {
      if (!f[i].set) {
        F(i, graph, f, nodes);
      }
      if (graph[i][node] + f[i].min < f[node].min) {
          f[node].min = graph[i][node] + f[i].min;
          f[node].min_index = i;
      }
    }
  }
}

void print_path(struct f_tuple *f, int node) {
  if (node == 0)
    return;
  printf("%d ", f[node].min_index);
  print_path(f, f[node].min_index);
}

struct f_tuple *f_tuple_array(int nodes) {
  struct f_tuple *f = malloc(nodes * sizeof(struct f_tuple));
  for (int i = 0; i < nodes; i++)
    f[i].set = 0;
  return f;
}
