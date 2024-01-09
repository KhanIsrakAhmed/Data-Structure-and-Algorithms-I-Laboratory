//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    07-07-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    if (key < node->data)
    {
        node->prev = insert(node->prev, key);
    }
    else if (key > node->data)
    {
        node->next = insert(node->next, key);
    }
    return node;
}
struct node *inOrderSuccesor(struct node *node)
{
    struct node *current = node;
    while (current && current->prev != NULL)
    {
        current = current->prev;
    }
    return current;
}
struct node *deletion(struct node *node, int key)
{
    if (key < node->data)
    {
        node->prev = deletion(node->prev, key);
    }
    else if (key > node->data)
    {
        node->next = deletion(node->next, key);
    }
    else
    {
        if (node->prev == NULL)
        {
            struct node *temp = node->next;
            free(node);
            return temp;
        }
        else if (node->next == NULL)
        {
            struct node *temp = node->prev;
            free(node);
            return temp;
        }
        struct node *temp = inOrderSuccesor(node->next);
        node->data = temp->data;
        node->next = deletion(node->next, key);
    }
    return node;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (root->data > key)
    {
        return search(root->prev, key);
    }
    if (root->data < key)
    {
        return search(root->next, key);
    }
}
void preOrderPrint(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preOrderPrint(node->prev);
    preOrderPrint(node->next);
}
void postOrderPrint(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    preOrderPrint(node->prev);
    preOrderPrint(node->next);
    cout << node->data << " ";
}
void inOrderPrint(struct node *node)
{
    if (node == NULL)
    {
        return;
    }
    inOrderPrint(node->prev);
    cout << node->data << " ";
    inOrderPrint(node->next);
}
// Sir,I have completed the bonus part.
int bSTHeight(struct node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int lheight = bSTHeight(node->prev);
    int rheight = bSTHeight(node->next);
    if (lheight > rheight)
    {
        return (lheight + 1);
    }
    else
        return (rheight + 1);
}

int main()
{
    struct node *root = NULL;
    cout << "how many nodes you want to add : ";
    int numOfNodes;
    cin >> numOfNodes;
    int NODE;
    cin >> NODE;
    root = insert(root, NODE);
    for (int i = 1; i < numOfNodes; i++)
    {
        cin >> NODE;
        insert(root, NODE);
    }
    cout << "\nPreorder : ";
    preOrderPrint(root);
    cout << "\nPostorder : ";
    postOrderPrint(root);
    cout << "\nInorder : ";
    inOrderPrint(root);
    cout << "Enter the value of the node that you want to be deleted : ";
    int delNode;
    cin >> delNode;
    deletion(root, delNode);
    cout << "\nEnter the key that you want to find in the tree : ";
    int key;
    cin >> key;
    if (search(root, key) == NULL)
        cout << key << " not found" << endl;
    else
        cout << key << " found" << endl;

    cout << "\nPreorder : ";
    preOrderPrint(root);
    cout << "\nPostorder : ";
    postOrderPrint(root);
    cout << "\nInorder : ";
    inOrderPrint(root);
    cout << "\nThe height of the tree : ";
    int y = bSTHeight(root);
    cout << " " << y;
    return 0;
}
