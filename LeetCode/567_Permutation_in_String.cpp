#include <string>
#include <map>
#include <iostream>

void addCharToMap(std::map<char, int>& map, char c)
{
    std::map<char, int>::iterator iter = map.find(c);
    if(iter == map.end())
        map[c] = 1;
    else
        iter->second++;
}

bool checkInclusion(std::string s1, std::string s2) {
    if(s2.length() < s1.length())
        return false;

    std::map<char, int> s1_map, s2_map;
    for(auto c : s1)
        addCharToMap(s1_map, c);

    for(int i = 0; i < s1.length(); i++)
        addCharToMap(s2_map, s2[i]);

    for(int i = 0; i <= s2.length() - s1.length(); i++)
    {
        std::map<char, int>::iterator iter_s1;
        for(iter_s1 = s1_map.begin(); iter_s1 != s1_map.end(); iter_s1++)
        {
            std::map<char, int>::iterator iter_s2 = s2_map.find(iter_s1->first);
            if(iter_s2 == s2_map.end() || iter_s2->second != iter_s1->second) // not found || count not equal
                break;
        }

        if(iter_s1 == s1_map.end())
            return true;

        if(i != s2.length() - s1.length())
        {
            // update s2_map via sliding window
            char new_c = s2[i + s1.length()];
            addCharToMap(s2_map, new_c);
            if(s2_map[s2[i]] == 1)
                s2_map.erase(s2[i]);
            else
                s2_map[s2[i]]--;
        }
    }
    return false;
}

int main()
{
    std::cout << checkInclusion("ab", "a");
    return 0;
}