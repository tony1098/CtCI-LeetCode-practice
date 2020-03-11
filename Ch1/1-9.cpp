#include <string>
#include <iostream>
// Assume given bool isSubstring(std::string s1, std::string s2)

bool isSubstring(std::string s1, std::string s2)
{
    int n1 = s1.length(), n2 = s2.length();
    if(n2 < n1)
    {
        std::string tmp  = s1;
        s1 = s2;
        s2 = tmp;
    }
    // s1.length() < s2.lenth()
    std::size_t found = s2.find(s1);
    if(found == std::string::npos)
        return false;
    else
        return true;
}

bool isStringRotation(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
        return false;

    s2 += s2;
    return isSubstring(s1, s2);
}

int main()
{
    std::string s1 = "waterbottle", s2 = "erbottlewat";
    std::cout << isStringRotation(s1, s2);
    return 0;
}