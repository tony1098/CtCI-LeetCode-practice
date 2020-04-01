#include <vector>
#include <random>
#include <iostream>


int binary_search(std::vector<int>& nums, int l, int r, int val)
{
    if(r < l)
        return -1;

    int mid = (l + r) / 2;
    if(val == nums[mid])
        return mid;
    else if(val < nums[mid])
        return binary_search(nums, l, mid - 1, val);
    else
        return binary_search(nums, mid + 1, r, val);
}

int magic_index(std::vector<int>& nums, int l, int r)
{
    if(r < l)
        return -1;

    int mid = (l + r) / 2;
    if(nums[mid] == mid)
        return mid;
    else if(nums[mid] < mid)
        return magic_index(nums, mid + 1, r);
    else
        return magic_index(nums, l, mid - 1);   
}

int main()
{

}