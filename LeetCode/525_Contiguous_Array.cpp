#include <vector>
#include <map>

int findMaxLength(std::vector<int>& nums) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
            sum += -1;
        else
            sum += 1;
        nums[i] = sum;
    }
    std::map<int, int> val_idx;
    for(int i = 0; i < nums.size(); i++)
    {
        if(val_idx.find(nums[i]) == val_idx.end())
            val_idx[nums[i]] = i;
    }
    int max = 0, len;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        std::map<int, int>::iterator iter = val_idx.find(nums[i]);
        if(nums[i] == 0)
            len = i + 1;
        else if(iter != val_idx.end())
            len = i - iter->second;              
        if(len > max)
            max = len;
    }
    return max;
}