#include <string>
#include <map>
#include <sstream>
#include <iostream>

bool wordPattern(std::string pattern, std::string str) {
    std::map<char, std::string> char_to_str;
    std::map<std::string, char> str_to_char;
    std::stringstream ss(str);
    int count = 0;
    std::string word;
    while(ss >> word)
        count++;
    if(count != pattern.length())
        return false;
    ss.str("");
    ss.clear();
    ss << str;
    for(int i = 0; i < pattern.length(); i++)
    {  
        ss >> word;
        if(char_to_str.find(pattern[i]) != char_to_str.end() || str_to_char.find(word) != str_to_char.end()) 
        {
            if(char_to_str[pattern[i]] != word || str_to_char[word] != pattern[i])
                return false;
            
        }
        else
        {
            char_to_str[pattern[i]] = word;
            str_to_char[word] = pattern[i];
        }
    }
    return true;
}

int main()
{
    std::cout << wordPattern("abba", "dog cat cat dog");
    /*
    std::stringstream ss;
    std::string word;
    ss << "abc" << " " << "def";
    while(ss >> word)
        ;
    ss.clear();
    ss << " " << "ghi";
    while(ss >> word)    
        std::cout << word;
    */
}