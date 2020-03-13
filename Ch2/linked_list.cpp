#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void push_back(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    
    ListNode *cur = head;
    while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

void push_front(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void print_list(ListNode *head)
{
    while(head != NULL)
    {
        std::cout << head->val << "->";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

void delete_value(ListNode *&head, int x)
{
    ListNode *prev = NULL, *cur = head;
    while(cur != NULL && cur->val != x)
    {
        prev = cur;
        cur = cur->next;
    }

    if(cur == NULL)
        std::cout << "There is no element " << x << std::endl;
    else if(cur == head)
    {
        head = head->next;
        delete cur;
        cur = 0;
    }
    else
    {
        prev->next = cur->next;
        delete cur;
        cur = 0;
    }
    
}