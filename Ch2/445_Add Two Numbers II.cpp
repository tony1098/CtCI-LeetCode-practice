#include <iostream>
#include <vector>
#include <stack>
#include "linked_list.cpp"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    std::stack<int> s1, s2;
    while(l1 != NULL)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }

    ListNode *head = NULL;
    int carry = 0;
    while(!s1.empty() && !s2.empty())
    {
        int sum = s1.top() + s2.top() + carry;
        push_front(head, sum % 10);
        if(sum >= 10)
            carry = sum / 10;
        else
            carry = 0;

        s1.pop();
        s2.pop();
    }
    if(s1.empty() && s2.empty()) 
    {
        if(carry != 0)
            push_front(head, carry);
        return head;
    }
    if(s1.empty()) // s1 is longer list
        s1 = s2;
    while(!s1.empty())
    {
        int sum = s1.top() + carry;
        push_front(head, sum % 10);
        if(sum >= 10)
            carry = sum / 10;
        else
            carry = 0;
        s1.pop();
    }
    if(carry != 0)
        push_front(head, carry);
    return head;
}

int main()
{
    ListNode *list1 = NULL, *list2 = NULL;
    push_back(list1, 7);
    push_back(list1, 2);
    push_back(list1, 4);
    push_back(list1, 3);
    push_back(list2, 5);
    push_back(list2, 6);
    push_back(list2, 4);
    std::cout << "list1: ";
    print_list(list1);
    std::cout << "list2: ";
    print_list(list2);
    list2 = addTwoNumbers(list1, list2);
    std::cout << "sum: ";
    print_list(list2);
}