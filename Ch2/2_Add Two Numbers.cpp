#include <iostream>
#include <vector>
#include "linked_list.cpp"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = NULL;
    int carry = 0;
    while(l1 != NULL && l2 != NULL)
    {
        int sum = l1->val + l2->val + carry;
        if(sum >= 10)
            carry = sum / 10;
        else
            carry = 0;
        
        push_back(head, sum % 10);
        l1 = l1->next;
        l2 = l2->next;
    }
    if(carry != 0 && l1 == NULL && l2 == NULL)
    {
        push_back(head, carry);
        return head;
    }

    // Case: lists of unequal length
    if(l1 == NULL) // l1 is longer list
        l1 = l2;

    while(l1 != NULL)
    {
        push_back(head, (l1->val + carry) % 10);
        carry = (l1->val + carry) / 10;
        l1 = l1->next;
    }
    if(carry != 0)
        push_back(head, carry);

    return head;
}

int main()
{
    ListNode *list1 = NULL, *list2 = NULL;
    push_back(list1, 3);
    push_back(list1, 4);
    push_back(list1, 2);
    push_back(list2, 4);
    push_back(list2, 6);
    push_back(list2, 5);
    std::cout << "list1: ";
    print_list(list1);
    std::cout << "list2: ";
    print_list(list2);
    list2 = addTwoNumbers(list1, list2);
    std::cout << "sum: ";
    print_list(list2);
}