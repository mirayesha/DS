#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//implementation of BST and its operations
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
}node;

node* create(int data)//creation of treenode
{
    node *root = malloc(sizeof(node));
    root->val = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node* insert(node *root, int num)//insertion in the binary search tree
{
    if(root == NULL)
    {
        return create(num);
    }
    if(num < root->val)
    {
        root->left = insert(root->left, num);
    }
    else if(root->val == num)
    {
        printf("Value already exists!");
        return NULL;
    }
    else
    {
        root->right = insert(root->right, num);
    }
    return root;
}
void inOrder(node *root)//traversal techniques
{
    if(root == NULL)
    {
        return;
    }
    inOrder(root->left);
    printf(" %d ",root->val);
    inOrder(root->right);
}

void preOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf(" %d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{
    if(root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ",root->val);
}


bool binarySearch(node* root, int val)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->val < val)
    return binarySearch(root->right, val);

    if(root->val > val)
    return binarySearch(root->left, val);

    else
    return true;
}

int main(void)
{
    node *root = NULL;
    root = create(50);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 60);
    printf("In Order Travesal: ");
    inOrder(root);
    printf("\nPre Order Traversal: ");
    preOrder(root);
    printf("\nPost Order Traversal: ");
    postOrder(root);
    printf("\nis 30 in the tree? %s", binarySearch(root, 90) ? "yes" : "no");
}

