#include <string>
#include <iostream>

bool within_one_edit(std::string s1, std::string s2)
{
    int len1 = s1.length(), len2 = s2.length();
    if(len1 < len2)
    {
        std::string tmp;
        tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    
    // Assert: s1 is always as long as s2
    int penalty = 0;
    if(s1.length() - s2.length() == 1) // insert/delete
    {
        for(int i = 0, j = 0; i < s1.length() && j < s2.length(); )
        {
            if(s1[i] == s2[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
                penalty++;
            }
        }
        if(penalty > 1)
            return false;
        else
            return true;
    }
    else if (s1.length() == s2.length()) // replace
    {
        
        for(int i = 0, j = 0; i < s1.length() && j < s2.length() && penalty <= 1;
            i++, j++)
        {
            if(s1[i] != s2[j])
                penalty++;
        }
        
        if(penalty <= 1)
            return false;
        else
            return true;
    }
    
    return false;
}

int main()
{
    std::string s1, s2;
    while(std::cin >> s1 >> s2)
    {
        if(within_one_edit(s1, s2))
            std::cout << "True" << std::endl;
        else
            std::cout << "False" << std::endl;
    }
    return 0;
}