#include <vector>
/*
int maxProfit(std::vector<int>& prices) {
    if(prices.empty())
        return 0;
    int i = 1, min = prices[0], max = -1;
    bool setMin = false;
    for(; i < prices.size() && !setMin; i++)
    {
        if(prices[i] < min)
            min = prices[i];
        else
        {
            setMin = true;
            break;
        }
    }
    int cur_max_profit = 0;
    for(; i < prices.size() && setMin; i++)
    {
        if(prices[i] < min)
        {
            min = prices[i];
            max = -1;
        }
        else if(prices[i] > max)
        {
            max = prices[i];
            if(cur_max_profit < max - min)
                cur_max_profit = max - min;
        }
    }
    return cur_max_profit;
}
*/

int maxProfit(std::vector<int>& prices) {
    if(prices.empty())
        return 0;
    int min = prices[0], max = -1;
    int cur_max_profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] < min)
        {
            min = prices[i];
            max = -1;
        }
        else if(prices[i] > max)
        {
            max = prices[i];
            if(cur_max_profit < max - min)
                cur_max_profit = max - min;
        }
    }
    return cur_max_profit;
}