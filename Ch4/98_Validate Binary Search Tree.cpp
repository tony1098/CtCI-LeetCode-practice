#include <cstddef>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int largestValueInBST(TreeNode *root)
{
    while(root->right != NULL)
        root = root->right;

    return root->val;
}

int smallestValueInBST(TreeNode *root)
{
    while(root->left != NULL)
        root = root->left;

    return root->val;
}

bool isValidBST(TreeNode* root) 
{
    if(root == NULL)
        return true;

    // check if root node is valid BST
    if(root->left != NULL && root->val <= largestValueInBST(root->left))
        return false;
    if(root->right != NULL && root->val >= smallestValueInBST(root->right))
        return false;

    if(!isValidBST(root->left) || !isValidBST(root->right))
        return false;  

    return true;
}

int main()
{

}