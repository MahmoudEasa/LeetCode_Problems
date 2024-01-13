/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *p1 = list1, *prev = list1, *p2;


    if (!list1) return (list2);
    if (!list2) return (list1);

    if (!list1->next && list1->val <= list2->val)
    {
        list1->next = list2;
        return (list1);
    }

    if (!list2->next && list2->val <= list1->val)
    {
        list2->next = list1;
        return (list2);
    }

 
    while(list2)
    {
        if (p1->val >= list2->val)
        {
            p2 = list2->next;
            list2->next = p1;
            if (prev == p1)
            {
                list1 = list2;
                prev = list1;
            }
            else
                prev->next = list2;
            list2 = p2;
            p1 = prev->next;
        }
        else
        {
            prev = p1;
            p1 = p1->next;
            if (!p1)
            {
                prev->next = list2;
                break;
            }
        }
    }

    return (list1);
}
