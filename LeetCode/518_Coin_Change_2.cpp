#include <vector>

int change(int amount, std::vector<int>& coins) {
    std::vector< std::vector<int> > num_changes(amount + 1, std::vector<int>(coins.size() + 1, 0));
    for(int i = 1; i <= amount; i++)
        num_changes[i][0] = 0;
    for(int j = 0; j <= coins.size(); j++)
        num_changes[0][j] = 1;
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 1; j <= coins.size(); j++)
        {
            if(i >= coins[j - 1])
                num_changes[i][j] = num_changes[i - coins[j - 1]][j] + num_changes[i][j - 1];
            else
                num_changes[i][j] = num_changes[i][j - 1];
        }
    }
    return num_changes[amount][coins.size()];
}