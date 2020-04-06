#include <vector>
#include <string>
#include <map>
#include <set>

std::vector< std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
    std::map<std::vector<int>, std::vector<std::string>> grouping;
    for(int i = 0; i < strs.size(); i++)
    {      
        std::vector<int> str_count(26, 0);
        for(auto c : strs[i])
            str_count[c - 'a']++;
        grouping[str_count].push_back(strs[i]);
    }
    std::vector< std::vector<std::string> > anagrams;
    for(auto group : grouping)
        anagrams.push_back(group.second);
    return anagrams;
}