#include <iostream>

int recursive_mult(int a, int b)
{
    if(a == 1) 
        return b;
    else if(a % 2 == 0)
        return recursive_mult(a / 2, b) + recursive_mult(a / 2, b);
    else
        return recursive_mult(a / 2, b) + recursive_mult(a / 2 + 1, b);
}

int main()
{
    std::cout << recursive_mult(1002932820, 1929238999);
    return 0;
}