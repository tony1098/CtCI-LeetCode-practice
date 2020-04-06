#include <string>
#include <map>

bool check(const std::string& s, int start, int end)
{
    for(int i = start, j = end; i <= (start + end) / 2; i++, j--)
    {
        if(s[i] != s[j])
            return false;
    }
    return true;
}

bool validPalindrome(std::string s) {
    for(int i = 0; i < s.length() / 2; i++)
    {
        if(s[i] != s[s.length() - 1 - i])
        {
            return check(s, i + 1, s.length() - 1 - i) || check(s, i, s.length() - 2 - i); 
        }
    }
    return true;
}

