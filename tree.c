#include <stdlib.h>
#include <stdio.h>

typedef struct _btnode
{
    int item;
    struct _btnode  *left;
    struct _btnode *right;
} BTNode;

BTNode* insertTree(BTNode *cur,int item) {
    if(cur == NULL) {
        printf("not found");
        return
    }
    if(cur->item == item){
        printf("%d ", cur->item);
        return NULL;
    }
    if(cur ->)
} 

int main() {
    newNode = malloc()
}
