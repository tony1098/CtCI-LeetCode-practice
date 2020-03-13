#include <iostream>
#include <vector>
#include "linked_list.cpp"

ListNode* insertionSortList(ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;

    // at least 2 elements in linked list
    ListNode *to_be_sorted = head->next;
    ListNode *prev_to_be_sorted = head;

    while(to_be_sorted != NULL)
    {
        ListNode *cur = head->next, *prev = head;
        
        // Case 1: insert before head
        if(to_be_sorted->val < head->val)
        {
            prev_to_be_sorted->next = to_be_sorted->next;
            ListNode *old_head = head;
            head = to_be_sorted;
            head->next = old_head;
            to_be_sorted = prev_to_be_sorted->next;
        }
        else
        {
            while(cur->val < to_be_sorted->val)
            {
                prev = cur;
                cur = cur->next;
            }    
            
            // Case 2: insertion between prev and cur
            if(cur != to_be_sorted)
            {
                prev_to_be_sorted->next = to_be_sorted->next;
                prev->next = to_be_sorted;
                to_be_sorted->next = cur;
                to_be_sorted = prev_to_be_sorted->next;
            }
            else
            {
                prev_to_be_sorted = to_be_sorted;
                to_be_sorted = to_be_sorted->next;
                continue;
            }
        }
        
        print_list(head);
    }

    return head;
}

int main()
{
    ListNode *head = NULL;
    push_back(head, 4);
    push_back(head, 2);
    push_back(head, 1);
    push_back(head, 3);
    push_back(head, 0);
    push_back(head, 10);
    print_list(head);
    head = insertionSortList(head);
}