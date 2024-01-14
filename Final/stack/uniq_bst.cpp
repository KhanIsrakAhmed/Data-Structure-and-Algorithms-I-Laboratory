#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int data)
    {
        val = data;
        left = right = NULL;
    }
};

void insert(TreeNode **root, int val)
{
    queue<TreeNode *> q;
    q.push(*root);
    while (q.size())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (!temp->left)
        {
            if (val != NULL)
                temp->left = new TreeNode(val);
            else
                temp->left = new TreeNode(0);
            return;
        }
        else
        {
            q.push(temp->left);
        }
        if (!temp->right)
        {
            if (val != NULL)
                temp->right = new TreeNode(val);
            else
                temp->right = new TreeNode(0);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

TreeNode *make_tree(int v[], int size)
{
    TreeNode *root = new TreeNode(v[0]);
    for (int i = 1; i < size; i++)
    {
        insert(&root, v[i]);
    }
    return root;
}

void tree_level_trav(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << "[";
    queue<TreeNode *> q;
    TreeNode *curr;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            q.push(NULL);
        }
        else
        {
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            if (curr == NULL || curr->val == 0)
            {
                cout << "null"
                     << ", ";
            }
            else
            {
                cout << curr->val << ", ";
            }
        }
    }
    cout << "]" << endl;
}

TreeNode *generate(int low, int high)
{
    if (low > high)
    {
        return NULL;
    }
    TreeNode *root = NULL;
    for (int i = low; i <= high; i++)
    {
        TreeNode *leftSubtree = generate(low, i - 1);
        TreeNode *rightSubtree = generate(i + 1, high);
        root = new TreeNode(i);
        root->left = leftSubtree;
        root->right = rightSubtree;
        tree_level_trav(root);
    }
    return root;
}

void generateTrees(int n)
{
    if (!n)
    {
        return;
    }
    generate(1, n);
}

int main()
{
    generateTrees(3);
    return 0;
}
