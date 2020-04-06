#include <vector>

bool checkPossibility(std::vector<int>& nums) {
    int count = 0;
    if(nums.size() < 3)
        return true;
    if(nums[0] > nums[1])
    {
        nums[0] = nums[1];
        count++;
    }
    for(int i = 2; i < nums.size() && count <= 1; i++)
    {
        if(nums[i - 1] > nums[i])
        {
            count++;
            if(nums[i - 2] <= nums[i])
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
        }
    }
    return count <= 1;
}