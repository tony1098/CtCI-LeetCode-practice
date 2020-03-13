#include <iostream>
#include "linked_list.cpp"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lenA = 0, lenB = 0;
    ListNode *tmpA = headA, *tmpB = headB;
    while(tmpA != NULL)
    {
        tmpA = tmpA->next;
        lenA++;
    } 
    while(tmpB != NULL)
    {
        tmpB = tmpB->next;
        lenB++;
    }        

    std::cout << "lenA = " << lenA << std::endl;
    std::cout << "lenB = " << lenB << std::endl;
    
    if(lenB > lenA) // headA length is always >= headB
    {
        ListNode *tmp = headA;
        headA = headB;
        headB = tmp;
        int tmp_len = lenA;
        lenA = lenB;
        lenB = tmp_len;
    }

    int diff = lenA - lenB;
    while(diff--)
        headA = headA->next;

    print_list(headA);
    print_list(headB);

    while(headA != NULL || headB != NULL)
    {
        if(headA == headB)
            return headA;

        headA = headA->next;
        headB = headB->next;
    }

    return headA;  
}

int main()
{
    ListNode *list1 = NULL, *list2 = NULL;
    push_back(list1, 0);
    push_back(list1, 9);
    push_back(list1, 1);
    push_back(list1, 2);
    push_back(list1, 4);

    push_back(list2, 3);
    ListNode *intersection = list1;
    
    for(int i = 0; i < 3; i++)
        intersection = intersection->next;
    list2->next = intersection;
    std::cout << "list1: ";
    print_list(list1);
    std::cout << "list2: ";
    print_list(list2);
    
    intersection = getIntersectionNode(list1, list2);
    std::cout << "Intersection: ";
    print_list(intersection);
}