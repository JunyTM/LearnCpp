#include<stdio.h>
#include<stdlib.h>

typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
    ListNode *head;
    ListNode *tail;
    int size;
} LinkedList;

typedef struct _queue {
    LinkedList ll;
} Queue;

// ---------------------------------------- type listode ---------------------------------------------

void printfList(ListNode *head){
    ListNode *cur = head;
    while(cur != NULL){
        printf("%d\t", cur -> num);
        cur = cur->next;
    }
    printf("\n");
}

ListNode *findNode(ListNode *head, int i) {
    ListNode *cur = head;
    if ((head == NULL) || (i < 0)) {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai\n");
        return NULL;
    }

    while(i > 0) {
        cur = cur->next ;
        i = i-1 ;
        if (cur == NULL) {
           printf("Phan tu tim kiem khong ton tai\n");
           return NULL;
        }
    }
    return cur;
}

void insertNode(ListNode **pHead, int index, int value){
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0 ){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead ; 
        *pHead = newNode ;
    }
    else if((cur = findNode(*pHead, index-1))!= NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next ;
        cur->next = newNode;
    } 
    else printf("\ncan not insert the new item at index %d!\n", index);
}

void removeNode(ListNode **ptrHead, int index){
    ListNode *cur, *pre;
    if (index == 0 ) {
        cur = *ptrHead ;
        *ptrHead = cur->next;
        free(cur);
    } 
    else {
        pre = findNode( *ptrHead , index-1);
        cur = pre->next ;
        pre->next = cur->next ;
        free(cur);
    }
} 

// ---------------------------------------- type Queue ---------------------------------------------

// void enqueue(Queue *q, int item){
//     if (q->ll.tail == NULL)
//     {
//         insertNode(&(q->ll.head), 0, item);
//         (q->ll).tail = (q->ll).head;
//     }
//     else
//     {
//         (q->ll).tail->next = malloc(sizeof(ListNode));
//         (q->ll).tail = ((q->ll).tail)->next;
//         (q->ll).tail->num = item;
//         (q->ll).tail->next = NULL;
//         (q->ll).size++;
//     }
// }

void enqueue(Queue *q, int item)
{
    insertNode(&(q->ll.head),q->ll.size,item);
    q->ll.size++;
}

int dequeue(Queue *q) {
    int item;
    if(q->ll.head!= NULL){
        item = ((q->ll).head)->num;
        removeNode(&(q->ll).head, 0);
        (q->ll).size--;
        return item;
    }
    else {
        printf("Hang doi rong\n");
        return 0;
    }
}

int peek(Queue *q){
    if (q->ll.head!=NULL)
        return (q->ll).head->num;
    else  {
        printf("Hang doi rong\n");
        return 0;
    }
}

int isEmptyQueue(Queue *q){
    if ((q->ll).size == 0) 
        return 1;
 
    return 0;
}