#include <vector>

int findDuplicate(std::vector<int>& nums) {
    int tortoise = nums[0], hare = nums[0];
    do
    {
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
    }
    while (tortoise != hare);
    hare = nums[0];
    while(tortoise != hare)
    {
        hare = nums[hare];
        tortoise = nums[tortoise];
    }
    return hare;
}