#include <vector>
/*
void generateSubsets(std::vector< std::vector<int> >& all_subsets, 
            std::vector<int>& nums, int i, std::vector<int> cur_subset)
{
    if(i == nums.size())
    {
        all_subsets.push_back(cur_subset);
        return;
    }
    generateSubsets(all_subsets, nums, i + 1, cur_subset);
    cur_subset.push_back(nums[i]);
    generateSubsets(all_subsets, nums, i + 1, cur_subset);
}

std::vector< std::vector<int> > subsets(std::vector<int>& nums) {
    std::vector< std::vector<int> > all_subsets;
    generateSubsets(all_subsets, nums, 0, std::vector<int>());
    return all_subsets;
}
*/
// iterative approach
std::vector< std::vector<int> > subsets(std::vector<int>& nums) {
    std::vector< std::vector<int> > all_subsets(1, std::vector<int>());
    for(auto num : nums)
    {
        int n = all_subsets.size();
        for(int i = 0; i < n; i++)
        {
            all_subsets.push_back(all_subsets[i]);
            all_subsets.back().push_back(num);
        }
    }
    return all_subsets;
}