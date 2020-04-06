#include <vector>

int maxSubArray(std::vector<int>& nums) {
    int n = nums.size(), max = nums[0];
    int c = nums[0];
    for(int i = 1; i < n; i++)
    {
        c = (c >= 0 ? c + nums[i] : nums[i]);
        if(c > max)
            max = c;
    }
    return max;
}