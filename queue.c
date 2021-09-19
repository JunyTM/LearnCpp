#include <stdlib.h>
#include <stdio.h>

typedef struct _listnode
{
    int num;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist
{
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;

typedef struct _queue
{
    LinkedList ll;

} Queue;

void printList(ListNode *head)
{
    ListNode *cache = head;
    while (cache != NULL)
    {
        printf("%d\t", cache->num);
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

//-------------------------------------------- type Queue ----------------------------------------------------

void enqueue(Queue *q, int item)
{
    if (q->ll.tail == NULL)
    {
        insertNode(&(q->ll.head), 0, item);
        (q->ll).tail = (q->ll).head;
    }
    else
    {
        (q->ll).tail->next = malloc(sizeof(ListNode));
        (q->ll).tail = ((q->ll).tail)->next;
        (q->ll).tail->num = item;
        (q->ll).tail->next = NULL;
        (q->ll).size++;
    }
}

int dequeue(Queue *q)
{
    int item;
    if(q->ll.head != NULL)
    {
        item = ((q->ll).head)->num;
        removeNode(&(q->ll).head, 0);
        (q->ll).size--;
        return item;
    }
    else
    {
        printf("Hang doi rong");
        return 0;
    }
}

int peek(Queue *q)
{
    if (q->ll.head != NULL)
        return (q->ll).head->num;
    else
    {

        printf("Hang doi rong");
        return 0;
    }
}

int isEmptyQueue(Queue *q)
{
    if ((q->ll).size == 0)
        return 1;
    return 0;
}

int main()
{
    Queue *q = malloc(sizeof(Queue));
    q->ll.size = 0;
    q->ll.head = NULL;
    q->ll.tail = NULL;

    int item;
    do
    {
        scanf("%d", &item);
        enqueue(q, item);
    } while ((q->ll).tail->num != 0);

    printList(q->ll.head);
    free(q);
}