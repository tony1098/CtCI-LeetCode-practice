#include <vector>
#include <set>

std::vector<int> dissect(int n)
{
    std::vector<int> num;
    while(n != 0)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    return num;
}

bool isHappy(int n) {
    int sum = n;
    std::set<int> seen;
    while(sum != 1)
    {
        auto iter_bool = seen.insert(sum);
        if(iter_bool.second == false)
            return false;
        std::vector<int> num = dissect(sum);
        sum = 0;
        for(int i = 0; i < num.size(); i++)
            sum += (num[i] * num[i]);
    }
    return true;
}