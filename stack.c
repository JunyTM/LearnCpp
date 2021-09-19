#include <stdlib.h>
#include <stdio.h>

typedef struct _listnode
{
    char num;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    ListNode *head;
    int size;
} LinkedList;

typedef struct _stack
{
    LinkedList ll;
} Stack;

void printList(ListNode *head)
{
    ListNode *cache = head;
    while (cache != NULL)
    {
        printf("%c\t", cache->num);
        cache = cache->next;
    }
}

ListNode *findNode(ListNode *head, int i)
{
    ListNode *cur = head;
    if ((head == NULL) || (i < 0))
    {
        printf("\nDanh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i > 0)
    {
        cur = cur->next;
        i = i - 1;
        if (cur == NULL)
        {
            printf("\nPhan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}

void insertNode(ListNode **pHead, int index, int value)
{
    ListNode *cur, *newNode;

    if (*pHead == NULL || index == 0) //start by index 0 && list none node
    {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    }
    else if ((cur = findNode(*pHead, index - 1)) != NULL)
    {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    }
    else
        printf("\ncan not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index)
{
    ListNode *cur, *pre;
    if (index == 0) //the first node will start by 0
    {
        cur = *ptrHead;
        *ptrHead = cur->next;
        free(cur);
    }
    else
    {
        pre = findNode(*ptrHead, index - 1); //take node in front of index of list
        cur = pre->next;
        pre->next = cur->next;
        free(cur);
    }
}

//---------------------------------- stack -------------------------------------

void push(Stack *s, int item)
{
    insertNode(&(s->ll.head), 0, item); //top of stack
    s->ll.size++;
}

int isEmptyStack(Stack *s)
{
    if (s->ll.size == 0)
        return 1;
    return 0;
}

int pop(Stack *s)
{
    int item;
    if (!isEmptyStack(s))
    {
        item = (s->ll).head->num;
        removeNode(&(s->ll).head, 0); //top of stack
        (s->ll).size--;
        return item;
    }
    else
    {

        printf("Ngan xep rong");
        return 0;
    }
}

int peek(Stack *s)
{
    if (s->ll.head != NULL)
        return (s->ll).head->num;
    else
    {
        printf("Ngan xep rong");
        return 0;
    }
}

int main()
{
    Stack *s = malloc(sizeof(Stack));
    s->ll.size = 0;
    s->ll.head = NULL;

    char item;
    do
    {
        scanf("%c", &item);
        push(s, item);
    } while ((s->ll).head->num != '0');
    pop(s);
    printList(s->ll.head);
    free(s);
}