#include <vector>
#include <stack>
#include <iostream>

class DinnerPlates {
public:
    std::vector<std::stack<int> > plates;
    int m_capacity, push_idx, pop_idx;    
    
    DinnerPlates(int capacity) {
        m_capacity = capacity;
        push_idx = pop_idx = 0;
        plates.push_back(std::stack<int>());
    }

    void print()
    {
        for(int i = 0; i < plates.size(); i++)
        {
            std::cout << i << "th stack: ";
            for(int j = 0; j < plates[i].size(); j++)
            {
                std::stack<int> tmp = plates[i];
                while(!tmp.empty())
                {
                    std::cout << tmp.top() << " ";
                    tmp.pop();
                }
            }
            std::cout << std::endl;
        }
    }
    
    void push(int val) 
    {
        if(plates[push_idx].size() < m_capacity)
        {
            plates[push_idx].push(val);
            return;
        }

        while(push_idx < plates.size() && plates[push_idx].size() == m_capacity)
            push_idx++;

        if(push_idx == plates.size())
        {
            plates.push_back(std::stack<int>());
            pop_idx = push_idx;
        }

        plates[push_idx].push(val);            
    }
    
    int pop() {
        if(plates[pop_idx].size() > 0)
        {
            int val = plates[pop_idx].top();
            plates[pop_idx].pop();
            return val;
        }

        while(plates[pop_idx].empty() && pop_idx > 0)
        {
            plates.pop_back();
            pop_idx--;
        }

        if(pop_idx < push_idx)
            push_idx = pop_idx;

        if(pop_idx == 0 && plates[0].empty())
            return -1;

        int val = plates[pop_idx].top();
        plates[pop_idx].pop();
        return val;
    }
    
    int popAtStack(int index) {
        
        if(index >= plates.size() || plates[index].empty())
            return -1;

        if(index < push_idx)
            push_idx = index;

        int val = plates[index].top();
        plates[index].pop();
        return val;
    }
};

int main()
{
    return 0;
}