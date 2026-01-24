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


node* binarySearch(node* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->val == val)
    {
        return root;
    }

    if(root->val < val)
    return binarySearch(root->right, val);

    if(root->val > val)
    return binarySearch(root->left, val);

}

node* subtreeFirst(node* root)//first node in inorder traversal
{
    if(root->left == NULL)
    {
        return root;
    }
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
node* deletion(node* root, int val)//deletion using successor logic
{
    if(root == NULL)
    return NULL;

    if(val < root->val)
    root->left = deletion(root->left, val);

    if(val > root->val)
    root->right = deletion(root->right, val);

    if(root->val == val)
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if(root->left == NULL)
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node* temp = subtreeFirst(root->right);
            root->val = temp->val;
            root->right = deletion(root->right, temp->val);
        }
    }
    return root;
}

int main(void)
{
    node *root = NULL;
    root = create(17);
    root = insert(root, 7);
    root = insert(root, 23);
    root = insert(root, 19);
    root = insert(root, 1);
    root = insert(root, 12);
    printf("In Order Travesal: ");
    inOrder(root);
    root = deletion(root, 17);
    printf("\nIn Order Travesal: ");
    inOrder(root);
}

