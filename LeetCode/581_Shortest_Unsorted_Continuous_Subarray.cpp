#include <vector>
#include <climits>


int findUnsortedSubarray(std::vector<int>& nums) {
    std::vector<int> copy(nums);
    std::sort(copy.begin(), copy.end());
    int n = nums.size();
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != copy[i])
            break;
        n--;  
    }
    for(int i = nums.size() - 1; i > 0; i--)
    {
        if(nums[i] != copy[i])
            break;
        n--;  
    }
    return n;
}