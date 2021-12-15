#include<stdio.h>
#include<stdlib.h>

typedef struct _listnode {
int num;
struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
ListNode *head;
int size;
} LinkedList;

typedef struct _stack {
LinkedList ll;
} Stack;



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

// ----------------------- type stack ----------------------------

int isEmptyStack(Stack *s){
    if ((s->ll).size == 0) 
        return 1;
    return 0;
}

void push(Stack *s, int item ) {
     insertNode( &(s->ll.head), 0, item);
     s->ll.size = s->ll.size+1 ;
}

int pop(Stack *s) {
     int item;
     if (!isEmptyStack(s)) {
          item = ((s->ll).head)->num;
          removeNode( &(s->ll).head, 0);
          (s->ll).size = (s->ll).size-1;
          return item ;
     }
     else {

          printf("Ngan xep rong\n");
          return 0;
     }
}


int peek(Stack *s) {
     if ( s->ll.head!=NULL )
          return (s->ll).head->num;
     else {

          printf("Ngan xep rong\n");
          return 0;
     }
}



// ------------------------------- main -------------------------------------
int main(void){
    Stack * s = malloc(sizeof(Stack));
    s->ll.size=0;
    s->ll.head=NULL;
    int value;

    push(s, 7);
    push(s, 9);
    push(s, 10);

    // printf("create stack\nn =");
    // scanf("%d", &n);
    //  for(int i = 0; i < n; i++){
    //     printf("value%d = ", i);
    //     scanf("%d", &value);
    //     push(s, value);
    // }
    
    printf("stack\n");
    printfList(s->ll.head);

    printf("push new value-12: \n");
    push(s, 12);

    printfList(s->ll.head);

    value = pop(s);
    printf("pop item = %d\n", value);

    printf("stack after pop\n");
    printfList(s->ll.head);

    printf("peek: %d\n",  peek(s));

    printf("isEmptyStack: %d\n", isEmptyStack(s));

    // printf("stack: ");
    // while(!isEmptyStack(s)){
    //     printf("%d ",pop(s));
    // }
    free(s);
}

// int main()
// {
//     Stack *s = malloc(sizeof(Stack));
//     s->ll.size = 0;
//     s->ll.head = NULL;

//     // push(s, 7);
//     // push(s, 9);
//     // push(s, 10);
//     int top, value;

//     int item;
//     printf("nhap stack (0 - stop):\n");
//     do
//     {
//         scanf("%d", &item);
//         push(s, item); //chèn vào ngăn xếp 
//     } while ((s->ll).head->num != 0);
//     pop(s);
     
//     printf("stack:\n");

//     printf("push new value:\n");
//     push(s, 12);
//     printList(s->ll.head);

    
//     top = peek(s);
//     printf("value top: %d\n",top);

//     value = pop(s);
//     printf("pop item = %d\n", value);
//     printList(s->ll.head);

    
//     // printf("stack: ");
//     // while(!isEmptyStack(s)){
//     //     printf("%d ",pop(s));
//     // }
//     free(s);
// }