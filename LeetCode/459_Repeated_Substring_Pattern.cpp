#include <string>

bool repeatedSubstringPattern(std::string s) {
    std::string repeating_seq;
    for(int i = 1; i <= s.length() / 2; i++)
    {
        if(s[i] == s[0] && (s.length() % i == 0))
        {
            repeating_seq = s.substr(0, i);

            int j;
            for(j = i; j < s.length(); j++)
            {
                if(repeating_seq[j % i] != s[j])
                    break;
            }
            if(j == s.length())
                return true;
        }
    }
    return false;
}