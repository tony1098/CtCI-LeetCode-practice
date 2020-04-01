#include <vector>
#include <iostream>

void recursive_permute(std::vector<int>& nums, std::vector<int> cur_permutation, 
            std::vector< std::vector<int> > &permutations)
{
    if(cur_permutation.size() == nums.size())
    {
        permutations.push_back(cur_permutation);
        return;
    }
    
    int cur_num = nums[cur_permutation.size()];

    for(int i = 0; i <= cur_permutation.size(); i++)
    {
        std::vector<int> copy_permutation = cur_permutation;
        copy_permutation.insert(copy_permutation.begin() + i, cur_num);
        recursive_permute(nums, copy_permutation, permutations);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector< std::vector<int> > permutations;
    recursive_permute(nums, std::vector<int>(), permutations);
    return permutations;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4};
    std::vector<std::vector<int>> permutations = permute(v);
    for(int i = 0; i < permutations.size(); i++)
    {
        for(auto num : permutations[i])
            std::cout << num << ", ";
        std::cout << std::endl;
    }
}

