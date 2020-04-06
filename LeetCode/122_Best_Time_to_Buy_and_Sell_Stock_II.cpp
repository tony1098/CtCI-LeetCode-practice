#include <vector>

int maxProfit(std::vector<int>& prices) {
    int sum = 0;
    for(int i = 1; i < prices.size(); i++)
        if(prices[i] - prices[i - 1] > 0)
            sum += prices[i] - prices[i - 1];
    return sum;
}  