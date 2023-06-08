#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node {
  int key;
  struct node *left, *right;
};

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root, FILE *file)
{
  if (root != NULL) {
    // Traverse left
    inorder(root->left, file);

    // Traverse root
    fprintf(file, "%d ", root->key);

    // Traverse right
    inorder(root->right, file);
  }
}

// Preorder Traversal
void preorder(struct node *root, FILE *file)
{
  if (root != NULL) {
    // Traverse root
    fprintf(file, "%d ", root->key);

    // Traverse left
    preorder(root->left, file);

    // Traverse right
    preorder(root->right, file);
  }
}

// Postorder Traversal
void postorder(struct node *root, FILE *file)
{
  if (root != NULL) {
    // Traverse left
    postorder(root->left, file);

    // Traverse right
    postorder(root->right, file);

    // Traverse root
    fprintf(file, "%d ", root->key);
  }
}

// Insert a node
struct node *insert(struct node *node, int key)
{
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Driver code
int main() {
  struct node *root = NULL;
  srand(time(0));
  int i;
  for (i = 0; i < 10; i++) {
    int randomNumber = rand() % 100 + 1;
    root = insert(root, randomNumber);
  }
  FILE *inorderFile = fopen("inorder.txt", "w");
  FILE *preorderFile = fopen("preorder.txt", "w");
  FILE *postorderFile = fopen("postorder.txt", "w");

  printf("Inorder traversal: ");
  inorder(root, inorderFile);
  fclose(inorderFile);
  printf("Saved to file: inorder.txt\n");

  printf("Preorder traversal: ");
  preorder(root, preorderFile);
  fclose(preorderFile);
  printf("Saved to file: preorder.txt\n");

  printf("Postorder traversal: ");
  postorder(root, postorderFile);
  fclose(postorderFile);
  printf("Saved to file: postorder.txt\n");

  return 0;
}
