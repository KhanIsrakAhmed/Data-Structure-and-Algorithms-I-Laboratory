#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

int maxValue(struct node *node)
{
    if (node == NULL)
    {
        return INT_MIN;
    }
    int value = node->data;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);

    return max(value, max(leftMax, rightMax));
}

int minValue(struct node *node)
{
    if (node == NULL)
    {
        return INT_MAX;
    }
    int value = node->data;
    int leftMin = minValue(node->left);
    int rightMin = minValue(node->right);

    return min(value, min(leftMin, rightMin));
}

/* Returns true if a binary tree is a binary search tree */
int isBST(struct node *node)
{
    if (node == NULL)
        return 1;

    /* false if the max of the left is > than us */
    if (node->left != NULL && maxValue(node->left) > node->data)
        return 0;

    /* false if the min of the right is <= than us */
    if (node->right != NULL && minValue(node->right) < node->data)
        return 0;

    /* false if, recursively, the left or right is not a BST
     */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}

/* Function to build a binary tree based on user input */
struct node *buildTree()
{
    int data;
    cout << "Enter root data (-1 for empty node): ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    struct node *root = newNode(data);
    cout << "Enter left subtree of " << data << ":" << endl;
    root->left = buildTree();
    cout << "Enter right subtree of " << data << ":" << endl;
    root->right = buildTree();

    return root;
}

/* Driver code */
int main()
{
    struct node *root = buildTree();

    // Function call
    if (isBST(root))
        printf("Is BST");
    else
        printf("Not a BST");

    return 0;
}
