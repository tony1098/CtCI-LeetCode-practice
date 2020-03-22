#include <iostream>
#include <vector>
#include <list>
#include "binary_tree.h"

void generateAllSequences(std::list<int> prefix, std::list<int> left_sequences, 
            std::list<int> right_sequences, std::vector< std::list<int> >& sequences)
{
    std::list<int> cur_seq;

    if(left_sequences.empty() || right_sequences.empty())
    {
        cur_seq = prefix;
        cur_seq.insert(cur_seq.end(), left_sequences.begin(), left_sequences.end());
        cur_seq.insert(cur_seq.end(), right_sequences.begin(), right_sequences.end()); 
        sequences.push_back(cur_seq);
        return;
    }
    
    int left_front = left_sequences.front();
    left_sequences.pop_front();
    prefix.push_back(left_front);
    generateAllSequences(prefix, left_sequences, right_sequences, sequences);
    prefix.pop_back();
    left_sequences.push_front(left_front);

    int right_front = right_sequences.front();
    right_sequences.pop_front();
    prefix.push_back(right_front);
    generateAllSequences(prefix, left_sequences, right_sequences, sequences);
    prefix.pop_back();
    right_sequences.push_front(right_front);
}


std::vector< std::list<int> > bst_sequences(TreeNode *root)
{
    std::vector< std::list<int> > sequences;

    if(root == NULL)
    {
        sequences.push_back(std::list<int>());
        return sequences;
    }

    std::list<int> prefix;
    prefix.push_back(root->val);

    std::vector< std::list<int> > left_sequences = bst_sequences(root->left);
    std::vector< std::list<int> > right_sequences = bst_sequences(root->right);

    for(auto left : left_sequences)
    {
        for(auto right : right_sequences)
        {
            generateAllSequences(prefix, left, right, sequences);
        }
    }

    return sequences; 
}

int main()
{
    TreeNode* root = new TreeNode(2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 4);
    std::cout << "Print BST inorder: ";
    print(root);
    std::cout << std::endl;
    std::vector< std::list<int> > all_sequences = bst_sequences(root);
    for(auto seq : all_sequences)
    {
        std::list<int>::iterator iter= seq.begin();
        while(iter != seq.end())
        {
            std::cout << *iter << " ";
            iter++;
        }
        std::cout << std::endl;
    }
}