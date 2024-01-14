

typedef struct node {
    int val;
    struct node *next;
    struct node *prev;
} Node;

typedef struct myStack {
    Node *head;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack * createStack = (MyStack *)malloc(sizeof(MyStack));


    if (!createStack) return (NULL);

    createStack->head = NULL;
    createStack->size = 0;
    return (createStack);
}

void myStackPush(MyStack* obj, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->val = x;
    newNode->next = NULL;
    newNode->prev = obj->head;

    if (!obj->head) obj->head = newNode;
    else
    {
        obj->head->next = newNode;
        obj->head = newNode;
    }

    obj->size++;
}

int myStackPop(MyStack* obj) {
    int val = obj->head->val;

    if (!obj->head->prev)
    {
        free(obj->head);
        obj->head = NULL;
    }
    else
    {
        obj->head = obj->head->prev;
        free(obj->head->next);
        obj->head->next = NULL;
    }

    obj->size--;
    return (val);
}

int myStackTop(MyStack* obj) {
    return (obj->head->val);
}

bool myStackEmpty(MyStack* obj) {
    return (!obj->size);
}

void myStackFree(MyStack* obj) {
    Node *ptr = obj->head;

    while (ptr)
    {
        ptr = ptr->prev;
        free(obj->head);
        obj->head = ptr;
    }

    obj->head = NULL;
    obj->size = 0;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
