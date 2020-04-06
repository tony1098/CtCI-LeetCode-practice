#include <vector>
#include <iostream>


    int removeDuplicates(std::vector<int>& nums) {
        int dist_idx = 0;
        if(nums.empty())
            return 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] != nums[i + 1])
            {
                dist_idx++;
                nums[dist_idx] = nums[i + 1];
            }
        }  
        return dist_idx + 1;      
    }

int main()
{
    std::vector<int> v{0,0,1,1,1,2,2,3,3,4};
    int n = removeDuplicates(v);
    for(int i = 0; i < n; i++)
        std::cout << v[i] << " ";
}