#include <vector>
#include <set>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        std::set<int> s(nums.begin(), nums.end());
        std::vector<int> missing;
        for(int i = 1; i <= nums.size(); i++)
        {
            if(s.find(i) == s.end())
                missing.push_back(i);
        }
        return missing;
    }
};

class Solution2 {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for(auto num : nums)
        {   
            int idx = abs(num) - 1;
            if(nums[idx] > 0)
                nums[idx] = -nums[idx];
        }
        std::vector<int> missing;   
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > 0)
                missing.push_back(i + 1);
        return missing;
    }
};