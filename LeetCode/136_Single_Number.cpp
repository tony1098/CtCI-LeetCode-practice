#include <vector>

int singleNumber(std::vector<int>& nums) {
    int n = 0;
    for(auto num : nums)
        n = n & num;
    return n;
}