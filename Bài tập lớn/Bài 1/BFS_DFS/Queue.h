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

void printfList(ListNode *head);
void enqueue(Queue *q, int item);
int dequeue(Queue *q);
int peek(Queue *q);
int isEmptyQueue(Queue *q);