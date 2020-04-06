#include <vector>
#include <iostream>
#include <map>
/*
int minSubArrayLen(int s, std::vector<int>& nums) {
    int min_size = INT_MAX, sum = 0;
    for(int end = 0, start = 0;  end < nums.size(); end++)
    {
        sum += nums[end];
        if(sum >= s)
        {
            while(sum - nums[start] >= s)
            {
                sum -= nums[start];
                start++;    
            }  
            if(end - start + 1 < min_size)
                min_size = end - start + 1;
        }
    }
    if(min_size == INT_MAX)
        return 0;
    else
        return min_size;
}
*/
int minSubArrayLen(int s, std::vector<int>& nums) {
    int sum = 0, min_size = INT_MAX;
    std::map<int, int> sum_idx;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        sum_idx[sum] = i;
        if(sum >= s)
        {
            std::map<int, int>::iterator iter = sum_idx.upper_bound(sum - s);
            if(i - iter->second + 1 < min_size)
                min_size = i - iter->second + 1;
        }
    }
    return min_size == INT_MAX ? 0 : min_size; 
}

int main()
{
    std::vector<int> v{2,3,1,2,4,3};
    std::cout << minSubArrayLen(7, v);
}