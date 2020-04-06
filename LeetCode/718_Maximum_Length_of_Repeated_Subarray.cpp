#include <vector>
#include <iostream>

int findLength(std::vector<int>& A, std::vector<int>& B) {
    std::vector<int> c(B.size() + 1, 0);
    int max = 0;
    for(int i = 1; i <= A.size(); i++)
    {
        for(int j = B.size(); j >= 1; j--)
        {
            max = std::max(max, c[j] = (A[i - 1] != B[j - 1] ? 0 : c[j - 1] + 1));
        }
    }
    return max;
}

int main()
{
    std::vector<int> v1{1,2,3,2,1}, v2{3,2,1,4,7};
    std::cout << findLength(v1, v2);
}