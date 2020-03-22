#include <stack>
#include <iostream>

std::stack<int> sort_stack(std::stack<int> orig_stack)
{
    std::stack<int> sorted_stack;

    sorted_stack.push(orig_stack.top());
    orig_stack.pop();

    while(!orig_stack.empty())
    {
        if(orig_stack.top() < sorted_stack.top())
        {
            sorted_stack.push(orig_stack.top());
            orig_stack.pop();
        }
        else
        {
            int orig_stack_top = orig_stack.top();
            orig_stack.pop();

            int num_count = 0;
            while(!sorted_stack.empty() && sorted_stack.top() < orig_stack_top)
            {
                orig_stack.push(sorted_stack.top());
                sorted_stack.pop();
                num_count++;
            }
            sorted_stack.push(orig_stack_top);
            while(num_count--)
            {
                sorted_stack.push(orig_stack.top());
                orig_stack.pop();
            }
        }     
    }

    return sorted_stack;
}

int main()
{
    std::stack<int> s, s_copy;
    srand (time(NULL));
    int count = 10;
    for(int i = 0; i < count; i++)
        s.push(rand() % 100);
    s_copy = s;
    for(int i = 0; i < count; i++)
    {
        std::cout << s_copy.top() << " ";
        s_copy.pop();
    }
    std::cout << std::endl;
    
    s = sort_stack(s);
    for(int i = 0; i < count; i++)
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;
}