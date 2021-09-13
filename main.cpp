#include<stdio.h>
#include<stdlib.h>
 
typedef struct _listnode {
	int num;
	struct _listnode *next;
}ListNode;

void printfList(ListNode *head) {
	ListNode *cur = head;
	if(cur = NULL) return ;
	while (cur != NULL){
        printf("%d\t", cur ->num);
        cur = cur ->next;
    }
	
}

int main () {
	int n;
	ListNode *newnode, *head;
	scanf("%d ",n);

	newnode = (ListNode *)malloc(sizeof(ListNode));
	head = newnode;
    node = newnode;

    for(int i = 0; i < n; i++ ) {
    	scanf("%d",&node -> num);
    	node = (ListNode *)malloc(sizeof(ListNode));
    	node = node->next;
	}

	scanf("%d ", &newnode->num);
	newnode->next=NULL;
    
	printfList(head);
}