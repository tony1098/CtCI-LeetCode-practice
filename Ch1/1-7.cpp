#include <vector>
#include <iostream>

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void rotate(std::vector<std::vector<int> > &matrix)
{
    int n = matrix[0].size();

    if(n <= 1)
        return;
    
    int center = (n - 1) / 2;
    int side_length = n;
    for(int radius = center; radius >= 0; radius--)
    {
        int upper_left_x = center - radius, upper_left_y = center - radius;

        for(int count = 0; count < side_length - 1; count++)
        {
            for(int y = 0; y < side_length - 1; y++)
            {
                swap(matrix[upper_left_y + y][upper_left_x], 
                        matrix[upper_left_y + y + 1][upper_left_x]);
            }
            for(int x = 0; x < side_length - 1; x++)
            {
                swap(matrix[upper_left_y + side_length - 1][upper_left_x + x], 
                        matrix[upper_left_y + side_length - 1][upper_left_x + x + 1]);
            }
            for(int y = 0; y < side_length - 1; y++)
            {
                swap(matrix[upper_left_y + side_length - 1 - y][upper_left_x + side_length - 1], 
                        matrix[upper_left_y + side_length - 2 - y][upper_left_x + side_length - 1]);
            }
            for(int x = 0; x < side_length - 2; x++)
            {
                swap(matrix[upper_left_y ][upper_left_x + side_length - 1 - x], 
                        matrix[upper_left_y][upper_left_x + side_length - 2 - x]);
            }
        }
        side_length -= 2;
    }
}

void printvec(std::vector< std::vector<int> > vec)
{
    int n = vec[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int n = 3, count = 0;
    std::vector< std::vector<int> > array_2D(n, std::vector<int>(n) );

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            array_2D[i][j] = count;
            count++;
        }
    }

    printvec(array_2D);
    rotate(array_2D);
    std::cout << "------------\n";
    printvec(array_2D);
}