//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    21-07-2023     *************************\

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

    cout << "Enter  left child of " << data << " " << endl;
    root->leftNode = buildTree(root->leftNode);

    cout << "Enter  right child of " << data << " " << endl;
    root->rightNode = buildTree(root->rightNode);

    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            /*
                 when temp becomes NULL,
                 at that moment last level parents childs are already
                 entered in the queue thst is why here adding new NULL object
            */
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->leftNode)
            {
                q.push(temp->leftNode);
            }
            if (temp->rightNode)
            {
                q.push(temp->rightNode);
            }
        } // goto 78 no line
    }
}

int32_t main()
{
    node *root = NULL;

    // creating tree
    root = buildTree(root);

    // input
    // 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

    // level order traversal
    cout << endl
         << "Tree Visualization level Order Traversal " << endl;
    levelOrderTraversal(root);

    return 0;
}
