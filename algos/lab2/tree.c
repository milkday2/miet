#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
  int key;
  struct treenode *left;
  struct treenode *right;
} treenode;

treenode *create_treenode(int key) {
  treenode *node = (treenode *)malloc(sizeof(treenode));
  if (node) {
    node->left = NULL;
    node->right = NULL;
    node->key = key;
  }
  return node;
}

treenode *sorted_tree(int *sorted_array, int len) {
  treenode *parent = create_treenode(sorted_array[len / 2]);
  if (len == 1) {
    return parent;
  }
  parent->left = sorted_tree(sorted_array, len / 2);
  if (len > 2)
    parent->right = sorted_tree(sorted_array + len / 2 + 1,
                                len % 2 ? len / 2 : len / 2 - 1);
  return parent;
}


void print_tree(treenode *node, int indent) {
  if (!node) {
    printf("{}");
    return;
  }
  printf("{%d", node->key);
  if (node->left || node->right) {
    printf(":\n");
    for (int i = 0; i < indent; i++) printf("    ");
    print_tree(node->left, indent + 1);
    printf(",\n");
    for (int i = 0; i < indent; i++) printf("    ");
    print_tree(node->right, indent + 1);
  }
  printf("}");
}

void insert_node(treenode **node, int value) {
  if (!(*node)) {
    (*node) = create_treenode(value);
    return;
  }
  if (value < (*node)->key)
    insert_node(&((*node)->left), value);
  else
    insert_node(&((*node)->right), value);
}

void delete_tree(treenode *node) {
  if (node) {
    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
  }
}

int main(void) {
  int arr[] = {1, 3, 5, 6, 9, 16, 21, 22, 30, 32, 41, 50};
  treenode *root = sorted_tree(arr, 12);
  insert_node(&(root), 45);
  print_tree(root, 1);
  delete_tree(root);
  return 0;
}
