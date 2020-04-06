#include <iostream>
#include <vector>
#include <cmath>

/*
int unique(int m, int n)
{
    if(m == 0)
        return 1;
    if(n == 0)
        return 1;

    return unique(m - 1, n) + unique(m, n - 1);
}
int uniquePaths(int m, int n) {
    return unique(m - 1, n - 1);
}


int uniquePaths(int m, int n) {
    std::vector< std::vector<int> > paths(m + 1, std::vector<int>(n + 1));
    for(int i = 0; i <= m; i++)
        paths[i][1] = 1;
    for(int j = 0; j <= n; j++)
        paths[1][j] = 1;
    for(int i = 2; i <= m; i++)
    {
        for(int j = 2; j <= n; j++)
        {
            paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
        }
    }
    return paths[m][n];
}
*/
int uniquePaths(int m, int n) {
    // C{m+n-2}{n-1}
    double res = 1;
    for(int num = m, denom = n - 1; num <= m + n - 2; num++, denom--)
    {
        res *= num;
        res /= denom;
    }
    return std::round(res);
}


int main()
{
    std::cout << uniquePaths(3, 2);
}