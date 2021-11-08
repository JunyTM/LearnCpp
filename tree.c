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
    printf("%d ", cur->item);
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
    printf("%d ", cur->item);
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
    BTNode *btnodeA, *btnodeB, *btnodeC, *btnodeD, *btnodeE, *btnodeF,
        *btnodeG, *btnodeH,
        *btnodeI, *btnodeJ, *btnodeK, *btnodeL, *btnodeM;
    // cấp phát 
    btnodeA = malloc(sizeof(BTNode));
    btnodeB = malloc(sizeof(BTNode));
    btnodeC = malloc(sizeof(BTNode));
    btnodeD = malloc(sizeof(BTNode));
    btnodeE = malloc(sizeof(BTNode));
    btnodeF = malloc(sizeof(BTNode));
    btnodeG = malloc(sizeof(BTNode));
    btnodeH = malloc(sizeof(BTNode));
    btnodeI = malloc(sizeof(BTNode));
    btnodeJ = malloc(sizeof(BTNode));
    btnodeK = malloc(sizeof(BTNode));
    btnodeL = malloc(sizeof(BTNode));
    btnodeM = malloc(sizeof(BTNode));

    btnodeA->item = 'A';
    btnodeB->item = 'B';
    btnodeC->item = 'C';
    btnodeD->item = 'D';
    btnodeE->item = 'E';
    btnodeF->item = 'F';
    btnodeG->item = 'G';
    btnodeH->item = 'H';
    btnodeI->item = 'I';
    btnodeJ->item = 'J';
    btnodeK->item = 'K';
    btnodeL->item = 'L';
    btnodeM->item = 'M';

    btnodeA->left = NULL;
    btnodeA->right = NULL;
    btnodeB->left = btnodeA;
    btnodeB->right = btnodeC;
    btnodeC->left = NULL;
    btnodeC->right = btnodeD;
    btnodeD->left = NULL;
    btnodeD->right = NULL;
    btnodeE->left = btnodeB;
    btnodeE->right = btnodeF;
    btnodeF->left = NULL;
    btnodeF->right = btnodeG;
    btnodeG->left = NULL;
    btnodeG->right = NULL;
    btnodeH->left = btnodeE;
    btnodeH->right = btnodeL;
    btnodeI->left = NULL;
    btnodeI->right = NULL;
    btnodeJ->left = btnodeI;
    btnodeJ->right = btnodeK;
    btnodeK->left = NULL;
    btnodeK->right = NULL;
    btnodeL->left = btnodeJ;
    btnodeL->right = btnodeM;
    btnodeM->left = NULL;
    btnodeM->right = NULL;

    // Thường sử dụng duyệt theo thứ tự giữa với cây tìm kiếm nhị phân 
    printf("\n\nCay nhi phan tim kiem truoc khi chen:\n ");
    TreeTraversal_InOrder(btnodeH);

    // Insert - chèn vào cây nhị phân
    char q = 'Q';

    // Tìm nút cha của Q 
    BTNode *posNode = BSTT2(btnodeH, q);

    // Tạo nút mới 
    BTNode *btNewNode = malloc(sizeof(BTNode));
    btNewNode->item = q;
    btNewNode->left = NULL;
    btNewNode->right = NULL;

    // Chèn vào cây
    if (posNode == NULL)
    {
        printf("Phan tu da ton tai");
        return 0;
    }
    if (q < posNode->item)
        posNode->left = btNewNode;
    else
    {

        posNode->right = btNewNode;
        printf("\n\nCay nhi phan tim kiem sau khi chen:\n ");
    }
    TreeTraversal_InOrder(btnodeH);


    
}