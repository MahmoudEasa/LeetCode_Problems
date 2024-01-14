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

int checkValue(int src, int val, int asciSteps, MyStack *obj)
{
    if (val == val && src != (val + asciSteps))
    {
        myStackFree(obj);
        return (0);
    }

    return (1);
}

bool isValid(char* s) {
    MyStack *obj = myStackCreate();
    short i, val;
    // (40 +1) [91 +2] {123 +2}

    for (i = 0; s[i]; i++)
    {
        val = 0;

        if (s[i] == 40 || s[i] == 123 || s[i] == 91)
        {
            myStackPush(obj, s[i]);
            continue;
        }

        if (!myStackEmpty(obj))
            val = myStackPop(obj);

        if (!val) return (0);

        if (val == 40)
            if (!checkValue(s[i], val, 1, obj)) return (0);

        if (val == 91 || val == 123)
            if (!checkValue(s[i], val, 2, obj)) return (0);
    }

    if (!myStackEmpty(obj))
    {
        myStackFree(obj);
        return (0);
    }

    return (1);
}
