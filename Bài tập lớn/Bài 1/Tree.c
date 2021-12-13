#include <stdlib.h>
#include <stdio.h>

// tạo kiểu dữ liệu mới là BTNode

typedef struct _btnode
{
    char item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void TreeTraversal_PreOrder(BTNode *cur) // duyệt theo thứ tự trước
{
    if (cur == NULL)
        return;
    printf("%c ", cur->item);
    TreeTraversal_PreOrder(cur->left);
    TreeTraversal_PreOrder(cur->right);
}

void TreeTraversal_InOrder(BTNode *cur) // duyệt theo thứ tự giữa
{
    if (cur == NULL)
        return;
    TreeTraversal_InOrder(cur->left);
    printf("%c ", cur->item);
    TreeTraversal_InOrder(cur->right);
}

void TreeTraversal_PostOrder(BTNode *cur) // duyệt theo thứ tự sau
{
    if (cur == NULL)
        return;
    TreeTraversal_PostOrder(cur->left);
    TreeTraversal_PostOrder(cur->right);
    printf("%c ", cur->item);
}

int main(void)
{
    // tạo nút
    BTNode *btnodeA, *btnodeB, *btnodeC, *btnodeD, *btnodeE, *btnodeH, *btnodeT;
    // cấp phát
    btnodeA = malloc(sizeof(BTNode));
    btnodeB = malloc(sizeof(BTNode));
    btnodeC = malloc(sizeof(BTNode));
    btnodeD = malloc(sizeof(BTNode));
    btnodeE = malloc(sizeof(BTNode));
    btnodeH = malloc(sizeof(BTNode));
    btnodeT = malloc(sizeof(BTNode));

    btnodeA->item = 'A';
    btnodeB->item = 'B';
    btnodeC->item = 'C';
    btnodeD->item = 'D';
    btnodeE->item = 'E';
    btnodeH->item = 'H';
    btnodeT->item = 'T';

    btnodeA->left = NULL;
    btnodeA->right = NULL;
    btnodeB->left = btnodeD;
    btnodeB->right = btnodeA;
    btnodeC->left = btnodeB;
    btnodeC->right = btnodeE;
    btnodeD->left = NULL;
    btnodeD->right = NULL;
    btnodeE->left = btnodeH;
    btnodeE->right = btnodeT;
    btnodeH->left = NULL;
    btnodeH->right = NULL;
    btnodeT->left = NULL;
    btnodeT->right = NULL;

    printf("\nDuyet theo thu tu truoc:\n ");
    TreeTraversal_PreOrder(btnodeC);

    printf("\nDuyet theo thu tu giua:\n ");
    TreeTraversal_InOrder(btnodeC);

    printf("\nDuyet theo thu tu sau:\n ");
    TreeTraversal_PostOrder(btnodeC);
}