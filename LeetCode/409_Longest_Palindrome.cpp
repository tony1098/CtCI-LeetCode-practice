#include <string>
#include <map>

int longestPalindrome(std::string s) {
    std::map<char, int> count;
    for(int i = 0; i < s.length(); i++)
    {
        if(count.find(s[i]) != count.end()) // found
            count[s[i]]++;
        else
            count[s[i]] = 1; 
    }
    bool one_odd = false;
    int palin_count = 0;
    for(std::map<char, int>::iterator iter = count.begin(); iter != count.end(); iter++)
    {
        palin_count += (iter->second % 2 == 0 ? iter->second : iter->second - 1);
        if(iter->second % 2 == 1)
            one_odd = true;
    }
    return one_odd ? palin_count + 1 : palin_count;
}