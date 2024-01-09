//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    08-07-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *leftNode;
    node *rightNode;
    node(int data)
    {
        this->data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "Enter the value of root: ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter left child of " << data << " \n";
    root->leftNode = buildTree(root->leftNode);

    cout << "Enter right child of " << data << " \n";
    root->rightNode = buildTree(root->rightNode);

    return root;
}

int main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    return 0;
}
/*

     input
    1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
*/