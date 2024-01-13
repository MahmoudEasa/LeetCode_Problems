/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 typedef struct stack {
     struct ListNode *head;
     struct ListNode *tail;
 } Stack;

 void push(Stack *stack, int val);

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode *ptr;
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    int i;


    // Initial Stack
    stack->head = NULL;
    stack->tail = NULL;

    if (!stack) return (NULL);

    for (i = 0; i < listsSize; i++)
    {
        ptr = lists[i];

        while (ptr)
        {
            push(stack, ptr->val);
            ptr = ptr->next;
        }
    }
    
    return (stack->head);
}

/**
* push - Add node
*/
void push(Stack *stack, int val)
{
    struct ListNode *new_list = (struct ListNode *)malloc(
        sizeof(struct ListNode));
    struct ListNode *ptr;
    

    if (!new_list) exit(1);

    new_list->next = NULL;
    new_list->val = val;

    if (!stack->head)
    {
        stack->head = new_list;
        stack->tail = new_list;
    }
    else
    {
        if (val > stack->tail->val)
        {
            stack->tail->next = new_list;
            stack->tail = new_list;
        }
        else
        {
            ptr = stack->head;
            
            if (!ptr->next || val < ptr->val)
            {
                new_list->next = ptr;
                stack->head = new_list;
                
             }
             else
                while (ptr->next)
                {
                    if (ptr->next->val >= val)
                    {
                        new_list->next = ptr->next;
                        ptr->next = new_list;
                        break;
                    }
                    ptr = ptr->next;
                }
        }
    }
}
