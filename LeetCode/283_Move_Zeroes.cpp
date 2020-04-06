#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int i = 0, j = 0;
    for(; i < nums.size() && j < nums.size(); i++, j++)
    {
        while(j < nums.size() && nums[j] == 0)
            j++;
        if(j == nums.size())
            break;
        nums[i] = nums[j];
    }
    while(i != nums.size())
    {
        nums[i] = 0;
        i++;
    }
}

int main()
{
    std::vector<int> v{0};
    moveZeroes(v);
}