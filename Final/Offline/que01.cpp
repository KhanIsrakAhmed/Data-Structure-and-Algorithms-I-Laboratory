//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    05-07-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

void insert(node *&root, int ele)
{
    if (root == NULL)
    {
        node *newNode = new node;
        newNode->value = ele;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return;
    }

    if (ele < root->value)
    {
        insert(root->left, ele);
    }
    else if (ele > root->value)
    {
        insert(root->right, ele);
    }
}

void Successor(node *root, node *&minNode)
{
    if (root == NULL)
    {
        return;
    }
    if (minNode == NULL || root->value > minNode->value)
    {
        minNode = root;
    }
    Successor(root->right, minNode);
}

void deleteNode(node *&root, int ele)
{
    if (root == NULL)
    {
        cout << "Value " << ele << " not in the tree." << endl;
        return;
    }

    if (ele < root->value)
    {
        deleteNode(root->left, ele);
    }
    else if (ele > root->value)
    {
        deleteNode(root->right, ele);
    }
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            root = temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            root = temp;
        }
        else
        {
            node *minNode = NULL;
            Successor(root->right, minNode);
            root->value = minNode->value;
            deleteNode(root->right, minNode->value);
        }
    }
}

bool find(node *root, int ele)
{
    if (root == NULL)
    {
        return false;
    }

    if (ele == root->value)
    {
        return true;
    }
    else if (ele < root->value)
    {
        return find(root->left, ele);
    }
    else
    {
        return find(root->right, ele);
    }
}

//-------------------------------------------------   Left-Right-Root

void printPostOrder(node *root)
{
    if (root != NULL)
    {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->value << " ";
    }
}

//-------------------------------------------------  Root-Left-Right

void printPreOrder(node *root)
{
    if (root != NULL)
    {
        cout << root->value << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

//------------------------------------------------   Left-Root-Right

void printInOrder(node *root)
{
    if (root != NULL)
    {
        printInOrder(root->left);
        cout << root->value << " ";
        printInOrder(root->right);
    }
}

int height(node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

void deleteTree(node *&root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = NULL;
}

int main()
{
    node *root = NULL;

    while (true)
    {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Insertion \t";
        cout << "2. Deletion \t";
        cout << "3. Search \t";
        cout << "4. Print Traversals \t";
        cout << "5. Calculate Height \t";
        cout << "6. Exit" << endl;

        int choice;
        cin >> choice;
        int ele;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to insert: ";
            cin >> ele;
            insert(root, ele);
            cout << "Value " << ele << " inserted into the tree." << endl;
            break;
        }
        case 2:
        {
            cout << "Enter value to delete: ";
            cin >> ele;
            deleteNode(root, ele);
            break;
        }
        case 3:
        {
            cout << "Enter value to search for: ";
            cin >> ele;
            if (find(root, ele))
            {
                cout << ele << " was found in the BST." << endl;
            }
            else
            {
                cout << ele << " was not found in the BST." << endl;
            }
            break;
        }

        case 4:
        {
            cout << "Choose a traversal type:" << endl;
            cout << "1. Post-Order \t";
            cout << "2. Pre-Order \t";
            cout << "3. In-Order \t" << endl;

            int traversalChoice;
            cin >> traversalChoice;

            switch (traversalChoice)
            {
            case 1:
                cout << "Post Order Traversal: ";
                printPostOrder(root);
                cout << endl;
                break;
            case 2:
                cout << "Pre Order Traversal: ";
                printPreOrder(root);
                cout << endl;
                break;
            case 3:
                cout << "In Order Traversal: ";
                printInOrder(root);
                cout << endl;
                break;
            default:
                cout << "Invalid choice.... " << endl;
                break;
            }
            break;
        }
        case 5:
        {
            int tHeight = height(root);
            cout << "Height of the tree: " << tHeight << endl;
            break;
        }
        case 6:
        {
            cout << "---------------------------------> Sayonara TwT <---------------------------------" << endl;
            deleteTree(root);
            return 0;
        }
        default:
        {
            cout << "Invalid choice.... " << endl;

            break;
        }
        }
    }

    return 0;
}