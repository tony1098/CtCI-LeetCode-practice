#include <vector>

int integerBreak(int n) {
    std::vector<int> c(n + 1, 0);
    c[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int k = 1; k < i; k++)
        {
            c[i] = std::max(c[i], std::max(i - k, c[i - k]) * std::max(k, c[k]));
        }
    }
    return c[n];
}