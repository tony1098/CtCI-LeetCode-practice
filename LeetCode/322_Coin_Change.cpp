#include <vector>

int coinChange(std::vector<int>& coins, int amount) {
    std::vector< std::vector<int> > fewestCoins(coins.size() + 1, std::vector<int>(amount + 1));
    fewestCoins[0][0] = 0;
    for(int j = 1; j <= amount; j++)
        fewestCoins[0][j] = 1e8;
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(j >= coins[i - 1])
                fewestCoins[i][j] = std::min(fewestCoins[i][j - coins[i - 1]] + 1, fewestCoins[i - 1][j]);
            else
                fewestCoins[i][j] = fewestCoins[i - 1][j];           
        }
    }
    if(fewestCoins[coins.size()][amount] == 1e8)
        return -1;
    else
        return fewestCoins[coins.size()][amount];
}

int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> fewestCoins(amount + 1);
    fewestCoins[0] = 0;
    for(int j = 1; j <= amount; j++)
        fewestCoins[j] = 1e8;
    for(int i = 1; i <= coins.size(); i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(j >= coins[i - 1])
                fewestCoins[j] = std::min(fewestCoins[j - coins[i - 1]] + 1, fewestCoins[j]);        
        }
    }
    if(fewestCoins[amount] == 1e8)
        return -1;
    else
        return fewestCoins[amount];
}