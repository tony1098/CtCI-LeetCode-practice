#include <vector>
#include <algorithm>

void permute(std::vector<int>& nums, std::vector<int> cur_sol, int cur_idx, 
            int start_pos, std::vector<bool> used, std::vector< std::vector<int> >& permutations)
{
    if(cur_idx == nums.size())
    {
        permutations.push_back(cur_sol);
        return;
    }
    for(int i = start_pos; i < nums.size(); i++)
    {
        if(!used[i])
        {
            used[i] = true;
            cur_sol[i] = nums[cur_idx];
            if(cur_idx < nums.size() - 1 && nums[cur_idx] == nums[cur_idx + 1]) 
                permute(nums, cur_sol, cur_idx + 1, i + 1, used, permutations);
            else
                permute(nums, cur_sol, cur_idx + 1, 0, used, permutations);
            used[i] = false;
        }
    }
}

std::vector< std::vector<int> > permuteUnique(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector< std::vector<int> > permutations;
    permute(nums, std::vector<int>(nums.size()), 0, 0, std::vector<bool>(nums.size()), permutations);
    return permutations;
}