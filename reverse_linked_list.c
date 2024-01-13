/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL, *next = head;

    while (next)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return (prev);
}
