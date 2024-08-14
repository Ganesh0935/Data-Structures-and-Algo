#include <stdio.h>
#include <stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
} *root = NULL, *temp = NULL, *p;

struct node *newNode(int x)
{
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct node *insert_bst(struct node *root, int x)
{
  if (root == NULL)
    return newNode(x);
  if (x < root->data)
  {
    root->left = insert_bst(root->left, x);
  }
  if (x > root->data)
  {
    root->right = insert_bst(root->right, x);
  }
  return root;
}

struct node *creation_bst(struct node *root)
{
  int n, i, x;
  printf("Enter number of nodes:");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &x);
    root = insert_bst(root, x);
  }
  return root;
}

void preOrder(struct node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(struct node *root)
{
  if (root != NULL)
  {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

void inOrder(struct node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

struct node *minvalue(struct node *root)
{
  p = root;
  while (p != NULL && p->left != NULL)
  {
    p = p->left;
  }
  return p;
}

struct node *maxvalue(struct node *root)
{
  p = root;
  while (p != NULL && p->right != NULL)
  {
    p = p->right;
  }
  return p;
}

struct node *delete(struct node *root, int x)
{
  if (root == NULL)
  {
    return root;
  }
  if (x < root->data)
  {
    root->left = delete (root->left, x);
  }
  else if (x > root->data)
  {
    root->right = delete (root->right, x);
  }
  else
  {
    if (root->left == NULL)
    {
      temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      temp = root->left;
      free(root);
      return temp;
    }
    else
    {
      temp = minvalue(root->right);
      root->data = temp->data;
      root->right = delete (root->right, temp->data);
    }
  }
}

int number_of_nodes(struct node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    return number_of_nodes(root->left) + number_of_nodes(root->right) + 1;
  }
}

int number_of_internal_nodes(struct node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  else if (root->left == NULL && root->right == NULL)
  {
    return 0;
  }
  else
  {
    return number_of_internal_nodes(root->left) + number_of_internal_nodes(root->right) + 1;
  }
}

int number_of_external_nodes(struct node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  else if (root->left == NULL && root->right == NULL)
  {
    return 1;
  }
  else
  {
    return number_of_external_nodes(root->left) + number_of_external_nodes(root->right);
  }
}

int height(struct node *root)
{
  int l, r;
  if (root == NULL)
  {
    return 0;
  }
  else
  {
    l = height(root->left);
    r = height(root->right);
    if (r > l)
    {
      return r + 1;
    }
    else
    {
      return l + 1;
    }
  }
}

void main()
{
  int c = 1, choice;
  while (c)
  {
    printf("Menu\n");
    printf("(1)-Creation of BST\n(2)-Pre Order traversal\n(3)-In Order traversal\n(4)-Post Order traversal\n(5)-Delete\n(6)-number of nodes\n(7)-number of internal nodes\n(8)-number of external nodes\n(9)-height of the tree\n(10)-minimum value\n(11)-maximum value\n");
    printf("Enter choice of your operation:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      root = creation_bst(root);
      break;
    }
    case 2:
    {
      preOrder(root);
      break;
    }
    case 3:
    {
      inOrder(root);
      break;
    }
    case 4:
    {
      postOrder(root);
      break;
    }
    case 5:
    {
      int x;
      printf("Enter value to delete:");
      scanf("%d", &x);
      root = delete (root, x);
      break;
    }
    case 6:
    {
      printf("\nThe number of nodes are %d\n", number_of_nodes(root));
      break;
    }
    case 7:
    {
      printf("\nThe number of internal nodes are %d\n", number_of_internal_nodes(root));
      break;
    }
    case 8:
    {
      printf("\nThe number of external nodes are %d\n", number_of_external_nodes(root));
      break;
    }
    case 9:
    {
      printf("\nThe height of tree is %d\n", height(root));
    }
    case 10:
    {
      temp = minvalue(root);
      printf("\nThe minimum value is %d\n", temp->data);
      break;
    }
    case 11:
    {
      temp = maxvalue(root);
      printf("\nThe maximum value is %d\n", temp->data);
      break;
    }
    }
    printf("Do you want to continue.?");
    scanf("%d",&c);
  }
}
