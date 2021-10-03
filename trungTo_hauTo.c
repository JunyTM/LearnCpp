#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

//gặp toán hạng thì thêm vào biểu thức
//gặp ( thì thêm vào stack
//gặp ) thì lấy tất cả trong stack vào biểu thức cho đến khi gặp (
//gặp toán tử nếu stack ko rỗng và độ ưu tiên toán tử trong stack >= toán tử đang gặp ==> pop đưa vào biểu thức
//ngược lại thì cứ đẩy vào trong stack

int isOperand(char ch)
{
    return ((ch >= 'A') && (ch <= 'z'));
}

int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

void infixToPostfix(char *exp, char *postfix)
{
    Stack *store = malloc(sizeof(Stack));
    store->ll.size = 0;
    store->ll.head = NULL;

    int k = -1;
    for (int i = 0; i < strlen(exp); i++)
    {
        if (isOperand(exp[i]))
        {
            k++;
            postfix[k] = exp[i];
        }
        else if (exp[i] == '(')
        {
            push(store, exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!isEmptyStack(store) && peek(store) != '(')
            {
                k++;
                postfix[k] = pop(store);
            }
            if (!isEmptyStack(store) && peek(store) != '(')
            {
                printf("bieu thuc khong hop le");
                return;
            }
            else
                pop(store);
        }
        else
        {
            while (!isEmptyStack(store) && Prec(exp[i]) <= Prec(peek(store)))
            {
                k++;
                postfix[k] = pop(store);
            }
            push(store, exp[i]);
        }
    }
    while (!isEmptyStack(store))
    {
        k++;
        postfix[k] = pop(store);
    }
    postfix[k++] = '\0';
}

int main(void)
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    char *postfix = malloc(sizeof(char) * (strlen(exp) + 1));
    infixToPostfix(exp, postfix);
    printf("%s", postfix);
}