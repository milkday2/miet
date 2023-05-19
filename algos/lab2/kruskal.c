// вариант 15
#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
  int nodes[2];
  int weight;
} edge;

typedef struct disjoint_set {
  int *parent;
  int size;
  int subset_count;
} disj_set;
void makeSet(disj_set *set, int n);
void freeSet(disj_set *set) { free(set->parent); }
int findParent(disj_set set, int v);
void merge(disj_set *set, int v1, int v2);
int sameSet(disj_set set, int v1, int v2);

edge *kruskal(edge *edges, int edge_count, int node_count);

int main(void) {
  int edges_arr[14][3] = {{1, 2, 4}, {2, 3, 1},  {3, 4, 1}, {1, 5, 9},
                          {2, 5, 3}, {1, 6, 10}, {2, 7, 2}, {3, 6, 1},
                          {3, 8, 7}, {4, 7, 8},  {4, 8, 6}, {5, 6, 4},
                          {6, 7, 1}, {7, 8, 5}};
  edge *edges = malloc(14 * sizeof(edge));
  for (int i = 0; i < 14; i++) {
    edges[i].nodes[0] = edges_arr[i][0];
    edges[i].nodes[1] = edges_arr[i][1];
    edges[i].weight = edges_arr[i][2];
  }
  edge *spanning_tree = kruskal(edges, 14, 8);
  for (int i = 0; i < 7; i++) {
    printf("%d - %d (%d)\n", spanning_tree[i].nodes[0],
           spanning_tree[i].nodes[1], spanning_tree[i].weight);
  }
  // Результат выполнения:
  // 2 - 3 (1)
  // 3 - 4 (1)
  // 3 - 6 (1)
  // 6 - 7 (1)
  // 2 - 5 (3)
  // 1 - 2 (4)
  // 7 - 8 (5)
  free(edges);
  free(spanning_tree);

  return 0;
}

edge *kruskal(edge *edges, int edge_count, int node_count) {
  edge *spanning_tree = malloc((node_count - 1) * sizeof(edge));
  edge temp;
  // sort edges
  for (int i = 0; i < edge_count - 1; i++) {
    for (int j = 0; j < edge_count - i - 1; j++)
      if (edges[j].weight > edges[j + 1].weight) {
        temp = edges[j];
        edges[j] = edges[j + 1];
        edges[j + 1] = temp;
      }
  }
  disj_set nodes;
  makeSet(&nodes, node_count);
  int k = 0;
  for (int i = 0; i < edge_count; i++) {
    if (!sameSet(nodes, edges[i].nodes[0], edges[i].nodes[1])) {
      spanning_tree[k++] = edges[i];
      merge(&nodes, edges[i].nodes[0], edges[i].nodes[1]);
    }
  }
  freeSet(&nodes);
  return spanning_tree;
}

void makeSet(disj_set *set, int n) {
  set->parent = malloc(n * sizeof(int) + 1);
  for (int i = 1; i <= n; i++)
    set->parent[i] = i;
  set->size = n;
  set->subset_count = n;
}

int findParent(disj_set set, int v) {
  if (set.parent[v] == v)
    return v;
  return findParent(set, set.parent[v]);
}

void merge(disj_set *set, int v1, int v2) {
  v1 = findParent(*set, v1);
  v2 = findParent(*set, v2);
  if (v1 == v2)
    return;
  set->parent[v2] = v1;
  set->subset_count++;
}

int sameSet(disj_set set, int v1, int v2) {
  return findParent(set, v1) == findParent(set, v2);
}
