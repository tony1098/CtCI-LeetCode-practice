#include <vector>
#include <queue>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::vector<std::vector<int> > levelOrder(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    std::vector<std::vector<int> > level_order;
    if(root == NULL)
        return level_order;
    while(true)
    {   
        std::vector<int> cur_level;
        while(q.front() != NULL)
        {
            if(q.front()->left != NULL)
                q.push(q.front()->left);
            
            if(q.front()->right != NULL)  
                q.push(q.front()->right);
            
            cur_level.push_back(q.front()->val);
            q.pop();
        }

        level_order.push_back(cur_level);
        q.pop();
        if(!q.empty())
            q.push(NULL);
        else
            break;        
    }
    return level_order;
}

int main()
{
    levelOrder(NULL);
    return 0;
}