#include <vector>
#include <iostream>

void convert(unsigned int n, std::vector<bool>& binary)
{
    if(n / 2 != 0)
        convert(n / 2, binary);
    binary.push_back(n % 2);
}

std::vector<bool> convertToBinary(unsigned int n)
{
    std::vector<bool> binary;
    convert(n, binary);
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

int flip_bit_to_win(std::vector<bool> binary)
{
    std::vector<int> consecutive_ones;
    for(int i = 0; i < binary.size();)
    {
        int ones_count = 0;
        while(binary[i] != 0 && i < binary.size())
        {
            ones_count++;
            i++;
        }
        if(ones_count != 0)
            consecutive_ones.push_back(ones_count);
        if(i >= binary.size())
            break;
        
        int zeros_count = 0;
        while(binary[i] == 0 && i < binary.size())
        {
            zeros_count++;
            i++;
        }
        if(zeros_count >= 2)
            consecutive_ones.push_back(0);
    }

    int max = 0;
    for(int i = 0; i < consecutive_ones.size() - 1; i++)
    {
        int sum = consecutive_ones[i] + consecutive_ones[i + 1] + 1;
        if(sum > max)
            max = sum;
    }
    return max;
}


int main()
{
    std::vector<bool> binary = convertToBinary(1775);
    print(binary);
    std::cout << flip_bit_to_win(binary) << std::endl;
}