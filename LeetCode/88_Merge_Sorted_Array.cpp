#include <vector>
#include <iostream>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int max_size = m > n ? m : n;
    std::vector<int> nums;
    nums.reserve(max_size);
    int i = 0, j = 0;
    while(i < m && j < n)
    {
        if(nums1[i] < nums2[j])
            nums.push_back(nums1[i++]);
        else
            nums.push_back(nums2[j++]);
    }
    while(i < m)
        nums.push_back(nums1[i++]);
    while(j < n)
        nums.push_back(nums2[j++]);
    nums1 = nums;
}

int main()
{
    std::vector<int> v1{4, 0, 0, 0, 0, 0};
    std::vector<int> v2{1,2,3,5,6};
    merge(v1, 1, v2, 5);
    for(auto v : v1)
        std::cout << v << " ";
}