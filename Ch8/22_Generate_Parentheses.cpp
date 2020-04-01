#include <string>
#include <vector>
#include <iostream>

void generate(int left_count, int right_count, std::string cur_str, std::vector<std::string>& all_parens)
{
    if(left_count == 0)
    {
        for(int i = right_count; i > 0; i--)
            cur_str += ")";
        all_parens.push_back(cur_str);
        return;
    }

    generate(left_count - 1, right_count, cur_str + "(", all_parens);
    if(right_count > left_count) 
        generate(left_count, right_count - 1, cur_str + ")", all_parens);
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> all_parens;
    generate(n, n, "", all_parens);
    return all_parens;
}

int main()
{
    std::vector<std::string> all_parens = generateParenthesis(3);
    for(auto paren : all_parens)
    {
        std::cout << paren << std::endl;
    }
}