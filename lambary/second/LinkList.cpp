#include"stdio.h"
#include"malloc.h"
#include"stdlib.h"
#include"bits/stdc++.h"
using namespace std;

typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    /* data */
}LNode, *LinkList;

void CreatList_L(LinkList &L, int n);
Status GetElem_L(LinkList L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);
Status ListDelete_L(LinkList &L, int i, ElemType &e);
Status Traverse_L(LinkList L);
Status Length_L(LinkList L);
Status Delete_Between(LinkList &L, ElemType mink, ElemType maxk);
int find_max(LinkList &L, int &e);

int main(){
    LinkList L;int n, i, i1, i2, e, e1, e2, j1, j2;

    printf("Please input the number in the list:");
    scanf("%d", &n);
    CreatList_L(L, n); Traverse_L(L);

    printf("The length is:%d\n", Length_L(L));
    printf("Get elem i:");scanf("%d", &i);
    GetElem_L(L, i, e);
    printf("The NO.%d elem is :%d\n", i, e);

    printf("Insert position:");scanf("%d", &i1);
    printf("Insert number:");scanf("%d", &e1);
    ListInsert_L(L, i1, e1);
    Traverse_L(L);

    printf("\nDelete between(a, b):");
    scanf("%d, %d", &j1, &j2);
    printf("The result :%d\n" , Delete_Between(L, j1, j2));
    Traverse_L(L);
    return 0;
}

void CreatList_L(LinkList &L, int n){
    LNode *p;  
    L = (LinkList)malloc(sizeof(LNode));
    L->data = 0;L->next = NULL;
    printf("Please input data:\n");
    for(int i =0; i<n; i++){
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
        L->data++;
    }
}

Status GetElem_L(LinkList L,int i, ElemType &e){
    LNode *p = L->next; int j = 1;
    while(p&&j<i){
        p = p->next;j++;
    }
    if(!p||j>i)return 0;
    e = p->data;
    return 1;
}

Status ListInsert_L(LinkList &L, int i, ElemType e){
    int j = 0; LNode*p = L, *s;
    while(p&&j<i-1){
        p = p->next;j++;
    }
    if(!p || j>i-1)return 0;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    L->data++;
    return 1;
}

Status ListDelete_L(LinkList &L, int i, ElemType &e){
    int j = 1;LNode *p = L->next, *q;
    while(p&&j<i-1){
        p = p->next;j++;
    }
    if(!p || j>i)return 0;
    q = p->next;p->next = q->next;
    e = q->data;
    L->data--;
    return 1;
}

Status Traverse_L(LinkList L){
    LNode *p = L->next;
    printf("This list contain %d elements\n", L->data);
    while(p){
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return 1;
}

Status Length_L(LinkList L){
    int count = 0;LNode *p = L->next;
    while(p) {p = p->next;count++;}
    return count;
}

Status Delete_Between(LinkList &L, ElemType mink, ElemType maxk){
    int j = 0; LNode *p = L->next, *q,*s;
    while (p&&p->data<maxk)
    {
        if(p->data>=mink){
            q = p->next;
            p->next = q->next;
            p = p->next;
            free(q);
            L->data--;
        }
        else
            p = p->next;
        /* code */
    }
    return 1;
}

int find_max(LinkList &L, int &e){
    if(L->next == NULL) return 0;
    LinkList p = L->next;int i = 1;
    while(p && i<=L->data){
        e = max(p->data, 0);
        p = p->next;
        i++;
    }
    return 1;
}
int reverse(LinkList &L){
    if(L->next == NULL) return 0;
    LinkList p, q, s;
    p = L->next;
    q  = p->next;
    while(q){
        s = q->next;
        q->next = p;
        p = q;
        q = s;
    }
    L->next = p;
    return 1;
}