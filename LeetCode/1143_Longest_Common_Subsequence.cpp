#include <string>
#include <vector>
#include <iostream>

enum State
{
    UP,
    LEFT,
    UPPER_LEFT
};

int longestCommonSubsequence(std::string text1, std::string text2, std::string &str) {
    std::vector< std::vector<int> > c(text1.length() + 1, std::vector<int>(text2.length() + 1, 0));
    std::vector< std::vector<State> > s(text1.length() + 1, std::vector<State>(text2.length() + 1));
    str = "";

    for(int i = 1; i <= text1.length(); i++)
    {
        for(int j = 1; j <= text2.length(); j++)
        {
            if(text1[i - 1] == text2[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = UPPER_LEFT;
            }
            else
            {
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
                if(c[i - 1][j] > c[i][j - 1])
                    s[i][j] = UP;
                else
                    s[i][j] = LEFT;
            }
        }
    }

    int i = text1.length(), j = text2.length();
    while(i != 0 || j != 0)
    {
        switch(s[i][j])
        {
            case UP:
                i--;
                break;
            case LEFT:
                j--;
                break;
            case UPPER_LEFT:
                i--; j--;
                str += text1[i];
                break;
        }
    }

    return c[text1.length()][text2.length()];
}

int main()
{
    std::string str;
    std::cout << longestCommonSubsequence("abc", "abc", str) << std::endl;
    std::cout << str;
}