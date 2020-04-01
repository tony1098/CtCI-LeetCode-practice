#include <vector>
#include <algorithm>
#include <iostream>
/*
bool cmp(std::vector<int> v1, std::vector<int> v2) // compare on first dim
{
    return v1[0] < v2[0];
}

int maxEnvelopes(std::vector< std::vector<int> >& envelopes, int idx, std::vector<int>& memo) 
// idx as base, and can only use boxes >= idx
{
    if(memo[idx] != -1)
        return memo[idx];

    int max = 0;
    for(int i = idx + 1; i < envelopes.size(); i++)
    {
        if(envelopes[idx][0] < envelopes[i][0] && envelopes[idx][1] < envelopes[i][1])
        {
            int n = maxEnvelopes(envelopes, i, memo);
            max = std::max(n, max);
        }
    }
    memo[idx] = 1 + max;
    return 1 + max;
}

int maxEnvelopes(std::vector< std::vector<int> >& envelopes) {
    std::sort(envelopes.begin(), envelopes.end(), cmp);
    int max = 0;
    std::vector<int> memo(envelopes.size(), -1);
    for(int i = 0; i < envelopes.size(); i++)
    {
        int n = maxEnvelopes(envelopes, i, memo);
        max = std::max(n, max);
    }
    return max;
}
*/

int maxEnvelopes(std::vector< std::vector<int> >& envelopes) {
    std::vector<int> max_env(envelopes.size());
    max_env[0] = 1;
    int max_w = envelopes[0][0], max_h = envelopes[0][1];
    for(int i = 1; i < envelopes.size(); i++)
    {
        if(envelopes[i][0] > max_w && envelopes[i][1] > max_h)
        {
            max_env[i] = max_env[i - 1] + 1;
            max_w = envelopes[i][0];
            max_h = envelopes[i][1];
        }
        else
            max_env[i] = max_env[i - 1];
    }
    return max_env[envelopes.size() - 1];
}

int main()
{
    std::vector< std::vector<int> > v;
    // [5,4],[6,4],[6,7],[2,3]
    v.push_back(std::vector<int>{5, 4});
    v.push_back(std::vector<int>{6, 4});
    v.push_back(std::vector<int>{6, 7});
    v.push_back(std::vector<int>{2, 3});
    std::cout << maxEnvelopes(v);
    return 0;
}