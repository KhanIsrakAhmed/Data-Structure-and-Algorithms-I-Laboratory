//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    24-07-2023     *************************\

#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *leftNode;
    struct Node *rightNode;
} node;

node *insert(node *&root, int key)
{
    node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->leftNode = NULL;
    newNode->rightNode = NULL;

    node *traveller = root;
    if (traveller == NULL)
    {
        return newNode;
    }
    cout << "ROOT " << root->data << endl;
    while (true)
    {
        if (traveller == NULL)
        {
            traveller = newNode;
            cout << "Tashin" << endl;
            break;
        }
        else
        {
            if (traveller->data < key)
            {
                traveller = traveller->rightNode;
            }
            else
            {
                traveller = traveller->leftNode;
            }
        }
    }

    return root;
}

void postOrderTraversal(node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->leftNode);
    postOrderTraversal(root->rightNode);
}

int32_t main()
{
    node *root = NULL;

    // input
    //  4 5 1 2 3 6 -1

    int data;
    while (1)
    {
        cout << "enter data: ";
        cin >> data;
        if (data == -1)
        {
            break;
        }
        root = insert(root, data);
    }

    cout << endl;
    cout << "Tree Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
