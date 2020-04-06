#include <string>
#include <map>

int lengthOfLongestSubstring(std::string s) {
    std::map<char, int> count;
    int max_size = 0;
    for(int i = 0, j = 0; j < s.length(); j++)
    {
        if(count.find(s[j]) != count.end()) // seen in map before
        {
            i = std::max(count[s[j]] + 1, i);
        }
        count[s[j]] = j;
        max_size = std::max(j - i + 1, max_size);

    }
    return max_size;
}

int main()
{
    lengthOfLongestSubstring("abba");
}