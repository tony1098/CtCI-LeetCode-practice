#include <iostream>
#include <vector>

int cutRod(int price[], int n) 
{
    std::vector<int> c(n + 1, 0);
    c[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= i; k++)
        {
            c[i] = std::max(c[i], c[i - k] + price[k - 1]);
        }
    }
    return c[n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    printf("Maximum Obtainable Value is %dn", cutRod(arr, size));
    return 0; 
}