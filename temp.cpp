#include <bits/stdc++.h>
using namespace std;
#define num 100
#define OK 1
typedef int Status;
typedef char DataType;
typedef struct node
{
    DataType data;
    struct node *lchild, *rchild;
} BinTNode, *BinTree;
Status CreateBiTree(BinTree &bt)
{
    char ch;
    scanf_s("%c", &ch);
    if (ch == '@')
        bt = NULL;
    else
    {
        bt = (BinTNode *)malloc(sizeof(BinTNode));
        bt->data = ch;
        CreateBiTree(bt->lchild);
        CreateBiTree(bt->rchild);
    }
    return OK;
}
Status Inorder(BinTree bt)
{
    BinTNode *stack[num];
    int top = 0;
    stack[top] = bt;
    do
    {
        while (NULL != stack[top])
        {
            top = top + 1;
            stack[top] = stack[top - 1]->lchild;
        }
        top = top - 1;
        if (top >= 0)
        {
            printf("%c", stack[top]->data);
            stack[top] = stack[top]->rchild;
        }
    } while (top >= 0);
    return OK;
}
Status PostOrder(BinTree BT)
{
    if (BT)
    {
        PostOrder(BT->lchild);
        PostOrder(BT->rchild);
        printf("%2c", BT->data);
    }
    return OK;
}
int size(BinTree BT)
{
    if (!BT)
    {
        return 0;
    }
    else
    {
        return 1 + size(BT->lchild) + size(BT->rchild);
    }
}
int LeafCount(BinTree BT)
{
    if (!BT)
    {
        return 0;
    }
    else if (!BT->lchild && !BT->rchild)
    {
        return 1;
    }
    else
    {
        return LeafCount(BT->lchild) + LeafCount(BT->rchild);
    }
}
int Depth(BinTree BT)
{
    int h, lh, rh;
    if (BT == NULL)
    {
        h = 0;
    }
    else
    {
        lh = Depth(BT->lchild);
        rh = Depth(BT->rchild);
        if (lh >= rh)
        {
            h = lh + 1;
        }
        else
        {
            h = rh + 1;
        }
    }
    return h;
}
BinTree Exchange(BinTree BT)
{
    BinTree temp;
    if (BT)
    {
        temp = BT->lchild;
        BT->lchild = BT->rchild;
        BT->rchild = temp;
        Exchange(BT->lchild);
        Exchange(BT->rchild);
    }
    return BT;
}
int main()
{
    BinTree bt = NULL;
    int xz = 1;
    int yz, sd;

    while (xz)
    {
        printf(" 二叉树的建立及其基本操作 \n");
        printf("=============================\n");
        printf(" 1.建立二叉树的存储结构 \n");
        printf(" 2.二叉树的基本操作 \n");
        printf(" 3.交换二叉树的左右 \n");
        printf(" 0.退出系统 \n");
        printf("=============================\n");
        printf(" 请选择：(0-3) \n");
        scanf_s("%d", &xz);
        getchar();
        switch (xz)
        {
        case 1:
            printf("输入二叉树的先序序列结点值:\n");
            CreateBiTree(bt);
            printf(" 二叉树的链式存储结构建立完成! \n");
            printf("\n");
            break;
        case 2:
            if (bt)
            {
                printf("该二叉树的后序遍历序列是: ");
                PostOrder(bt);
                printf("\n");
                printf("该二叉树的中序遍历序列是: ");
                Inorder(bt);
                printf("\n");
                printf("该二叉树的结点个数是:%4d\n", size(bt));
                yz = LeafCount(bt);
                printf("叶子结点个数是:%4d\n", yz);
                sd = Depth(bt);
                printf("该二叉树的深度是:%4d\n", sd);
                printf("\n");
            }
            else
            {
                printf("请先建立一个二叉树。\n ");
            }
            break;
        case 3:
            Exchange(bt);
            printf("该二叉树已交换左右子树！ \n");
            printf(" \n");
            break;
        case 0:
            break;
        }
    }
    return 0;
}