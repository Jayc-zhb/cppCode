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
// 中序
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
// 先序
Status BeforeInoder(BinTree bt){
    if(bt){
        cout << bt->data << ' ';
        BeforeInoder(bt->lchild);
        BeforeInoder(bt->rchild);
    }
    return OK;
}
// 后序
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
    cout << "二叉树的建立及其操作\n";
    cout << "====================\n";
    cout << "1.建立二叉树的存储结构 \n";
    cout << "2.二叉树的基本操作 \n";
    cout << "3.交换二叉树的左右 \n";
    cout << "0.退出系统 \n";
    cout << "====================\n";
    while(xz){
        cout << "请选择(0~3):\n";
        cin >> xz;
        
        switch(xz){
            case 1:
                cout << "输入结点先序结点的遍历值：\n";
                CreateBiTree(bt);
                cout << "二叉树建立完毕!\n\n";
                break;
            case 2:
                if(bt){
                    cout << "二叉树后序遍历是:\n";
                    PostInoder(bt);
                    cout << "\n二叉树中序遍历是:\n";
                    Inorder(bt);
                    cout << "\n该二叉树的结点个数是:  " << size(bt) << '\n';
                    cout << "\n叶子结点个数是:  " << LeafCount(bt) << '\n';
                    cout << "\n该二叉树的深度是:  " << Deepth(bt) << '\n' << '\n';

                }
                else{
                    cout << "请先建立一个二叉树!\n" << '\n';
                }
                break;
            case 3:
                Swap(bt);
                cout << "该二叉树左右子树已经交换!\n" << '\n';
                break;
            case 0:
                cout << "操作结束，再见！\n" << '\n';
                break;
        }
    }
    return 0;
}