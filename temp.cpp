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
        printf(" �������Ľ�������������� \n");
        printf("=============================\n");
        printf(" 1.�����������Ĵ洢�ṹ \n");
        printf(" 2.�������Ļ������� \n");
        printf(" 3.���������������� \n");
        printf(" 0.�˳�ϵͳ \n");
        printf("=============================\n");
        printf(" ��ѡ��(0-3) \n");
        scanf_s("%d", &xz);
        getchar();
        switch (xz)
        {
        case 1:
            printf("������������������н��ֵ:\n");
            CreateBiTree(bt);
            printf(" ����������ʽ�洢�ṹ�������! \n");
            printf("\n");
            break;
        case 2:
            if (bt)
            {
                printf("�ö������ĺ������������: ");
                PostOrder(bt);
                printf("\n");
                printf("�ö��������������������: ");
                Inorder(bt);
                printf("\n");
                printf("�ö������Ľ�������:%4d\n", size(bt));
                yz = LeafCount(bt);
                printf("Ҷ�ӽ�������:%4d\n", yz);
                sd = Depth(bt);
                printf("�ö������������:%4d\n", sd);
                printf("\n");
            }
            else
            {
                printf("���Ƚ���һ����������\n ");
            }
            break;
        case 3:
            Exchange(bt);
            printf("�ö������ѽ������������� \n");
            printf(" \n");
            break;
        case 0:
            break;
        }
    }
    return 0;
}