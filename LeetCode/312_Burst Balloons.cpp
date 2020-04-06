#include <vector>
#include <algorithm>

int maxCoins(std::vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    std::vector< std::vector<int> > cost(n + 2, std::vector<int>(n + 2, 0));
    for(int len = 1; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            for(int k = i; k <= j; k++)
            {
                cost[i][j] = std::max(cost[i][j], cost[i][k - 1] + cost[k + 1][j] 
                            + nums[i - 1] * nums[k] * nums[j + 1]);
            }
        }
    }
    return cost[1][n];
}