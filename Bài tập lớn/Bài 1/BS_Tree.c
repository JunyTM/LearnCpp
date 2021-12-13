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

BTNode *BSTT(BTNode *cur, char c)   // tìm nút trên cây tìm kiếm nhị phân 
{
    if (cur == NULL)
        return NULL;
    if (c == cur->item)
        return cur;
    if (c < cur->item)
        return cur->left;
    else
        return cur->right;
}

BTNode *BSTT2(BTNode *cur, char c)  // tìm vị trí nút cha của nút cần chèn vào cây tìm kiếm nhị phân
{
    if (c == cur->item)
        return NULL;
    if (c < cur->item)
    {
        if (cur->left == NULL)
            return cur;
        return BSTT2(cur->left, c);
    }
    else
    {
        if (cur->right == NULL)
            return cur;
        return BSTT2(cur->right, c);
    }
}

int main(void)
{
    // tạo nút
    BTNode *btnodeA, *btnodeC, *btnodeE, *btnodeF,
        *btnodeG, *btnodeH, *btnodeT;
    // cấp phát 
    btnodeA = malloc(sizeof(BTNode));
    btnodeC = malloc(sizeof(BTNode));
    btnodeE = malloc(sizeof(BTNode));
    btnodeF = malloc(sizeof(BTNode));
    btnodeG = malloc(sizeof(BTNode));
    btnodeH = malloc(sizeof(BTNode));
    btnodeT = malloc(sizeof(BTNode));

    btnodeA->item = 'A';
    btnodeC->item = 'C';
    btnodeE->item = 'E';
    btnodeF->item = 'F';
    btnodeG->item = 'G';
    btnodeH->item = 'H';
    btnodeT->item = 'T';

    btnodeA->left = NULL;
    btnodeA->right = NULL;
  
    btnodeC->left = btnodeA;
    btnodeC->right = btnodeE;

    btnodeE->left = NULL;
    btnodeE->right = NULL;

    btnodeF->left = btnodeC;
    btnodeF->right = btnodeH;

    btnodeG->left = NULL;
    btnodeG->right = NULL;

    btnodeH->left = btnodeG;
    btnodeH->right = btnodeT;
    
    btnodeT->left = NULL;
    btnodeT->right = NULL;

    //cây tìm kiếm nhị phân ban đầu 
    printf("\nCay tim kiem nhi phan truoc khi chen:\n ");
    TreeTraversal_InOrder(btnodeF);

    char D = 'D';
    // Tìm nút cha của Q 
    BTNode *posNode = BSTT2(btnodeF, D);

    // Tạo nút mới 
    BTNode *btNewNode = malloc(sizeof(BTNode));
    btNewNode->item = D;
    btNewNode->left = NULL;
    btNewNode->right = NULL;

    // Chèn vào cây
    if (posNode == NULL)
    {
        printf("Phan tu da ton tai");
        return 0;
    }
    if (D < posNode->item)
        posNode->left = btNewNode;
    else
    {
        posNode->right = btNewNode;
        
    }
    printf("\nCay nhi phan tim kiem sau khi chen:\n ");
    TreeTraversal_InOrder(btnodeF);


    
}