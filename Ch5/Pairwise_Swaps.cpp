#include <vector>
#include <iostream>

void convert(int n, std::vector<bool>& binary)
{
    if(n / 2 != 0)
        convert(n / 2, binary);
    binary.push_back(n % 2);
}

std::vector<bool> convertToBinary(int n)
{
    std::vector<bool> binary;
    convert(n, binary);
    // fill with preceeding zeros
    binary.insert(binary.begin(), 32 - binary.size(), 0);
    return binary;
}

void print(const std::vector<bool>& binary)
{
    for(int i = 0; i < binary.size(); i++)
    {
        std::cout << binary[i];
    }
    std::cout << std::endl;
}

int pairwise_swaps(int n)
{
    int even_mask = 0xAAAAAAAA, odd_mask = 0x55555555;
    int tmp = (n & even_mask) >> 1;
    int tmp2 = (n & odd_mask) << 1;
    return tmp | tmp2;
}

int main()
{
    std::vector<bool> binary = convertToBinary(1725);
    print(binary);
    print(convertToBinary(pairwise_swaps(1725)));
}