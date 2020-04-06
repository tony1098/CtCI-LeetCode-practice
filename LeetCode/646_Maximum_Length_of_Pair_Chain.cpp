#include <vector>
#include <utility>

bool cmp(std::vector<int> v1, std::vector<int> v2)
{
    return v1[1] < v2[1];
}

int findLongestChain(std::vector<std::vector<int>>& pairs) {
    std::sort(pairs.begin(), pairs.end(), cmp);
    if(pairs.empty())
        return 0;
    std::vector<int> cur_v = pairs[0];
    int count = 1;
    for(int i = 1; i < pairs.size(); i++)
    {
        if(pairs[i][0] > cur_v[1])
        {
            cur_v = pairs[i];
            count++;
        }
    }
    return count;
}

int main()
{
    return 0;
}