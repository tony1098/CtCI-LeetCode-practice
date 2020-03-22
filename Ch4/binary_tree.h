#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void insert(TreeNode*& node, int val)
{
    TreeNode *newNode = new TreeNode(val);
    TreeNode *prev = NULL;
    TreeNode *cur = node;

    while(cur != NULL)
    {
        prev = cur;
        if(val <= cur->val)
            cur = cur->left;
        else
            cur = cur->right;
    }

    if(prev == NULL)
        node = newNode;
    else if(val <= prev->val)
        prev->left = newNode;
    else
        prev->right = newNode;
}

void print(TreeNode *root)
{
    if(root != NULL)
    {
        print(root->left);
        std::cout << root->val << " ";
        print(root->right);
    }
}