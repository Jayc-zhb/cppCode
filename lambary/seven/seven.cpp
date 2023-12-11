#include<bits/stdc++.h>
using namespace std;

#define num 100
#define OK 1

typedef int Status;
typedef char DataType;

typedef struct node{
    DataType data;
    struct node*lchild, *rchild;
}BinTnode, *BinTree;

Status CreateBiTree(BinTree &bt){
    char ch;
    cin >> ch;
    if(ch == '@')bt = NULL;
    else{
        bt = (BinTnode*)malloc(sizeof(BinTnode));
        bt->data = ch;
        CreateBiTree(bt->lchild);
        CreateBiTree(bt->rchild);
    }
    return OK;
}
// ����
Status Inorder(BinTree bt){
    BinTnode*stack[num];
    int top = 0;
    stack[top] = bt;
    do{
        while(NULL != stack[top]){
            top = top+1;
            stack[top] = stack[top-1]->lchild;
        }
        top = top-1;
        if(top>=0){
            cout << stack[top]->data;
            stack[top] = stack[top]->rchild;
        }
    }while(top>=0);
    return OK;
}
// ����
Status BeforeInoder(BinTree bt){
    if(bt){
        cout << bt->data << ' ';
        BeforeInoder(bt->lchild);
        BeforeInoder(bt->rchild);
    }
    return OK;
}
// ����
Status PostInoder(BinTree bt){
    if(bt){
        PostInoder(bt->lchild);
        PostInoder(bt->rchild);
        cout << bt->data;
    }
    return OK;
}

Status size(BinTree bt){
    if(!bt)return 0;
    else return 1+size(bt->lchild)+size(bt->rchild);
}

Status LeafCount(BinTree bt){
    if(!bt)return 0;
    else if(!bt->lchild && !bt->rchild)return 1;
    else return LeafCount(bt->lchild)+LeafCount(bt->rchild);
}

Status Deepth (BinTree bt){
    int h, lh, rh;
    if(bt == NULL){
        h = 0;
    }
    else {
        lh = Deepth(bt->lchild);
        rh = Deepth(bt->rchild);
        h = max(lh, rh)+1;
    }
    return h;
}

BinTree Swap(BinTree bt){
    BinTree temp;
    if(bt){
        temp = bt->lchild;
        bt->lchild = bt->rchild;
        bt->rchild = temp;
        Swap(bt->lchild);
        Swap(bt->rchild);
    }
    return bt;
}
int main(){
    BinTree bt = NULL;
    int xz = 1, yz, sd;
    cout << "�������Ľ����������\n";
    cout << "====================\n";
    cout << "1.�����������Ĵ洢�ṹ \n";
    cout << "2.�������Ļ������� \n";
    cout << "3.���������������� \n";
    cout << "0.�˳�ϵͳ \n";
    cout << "====================\n";
    while(xz){
        cout << "��ѡ��(0~3):\n";
        cin >> xz;
        
        switch(xz){
            case 1:
                cout << "������������ı���ֵ��\n";
                CreateBiTree(bt);
                cout << "�������������!\n\n";
                break;
            case 2:
                if(bt){
                    cout << "���������������:\n";
                    PostInoder(bt);
                    cout << "\n���������������:\n";
                    Inorder(bt);
                    cout << "\n�ö������Ľ�������:  " << size(bt) << '\n';
                    cout << "\nҶ�ӽ�������:  " << LeafCount(bt) << '\n';
                    cout << "\n�ö������������:  " << Deepth(bt) << '\n' << '\n';

                }
                else{
                    cout << "���Ƚ���һ��������!\n" << '\n';
                }
                break;
            case 3:
                Swap(bt);
                cout << "�ö��������������Ѿ�����!\n" << '\n';
                break;
            case 0:
                cout << "�����������ټ���\n" << '\n';
                break;
        }
    }
    return 0;
}