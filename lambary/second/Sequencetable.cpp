#include"stdio.h"
#include"stdlib.h"
#include"malloc.h"
#include"math.h"

#define True 1
#define False 0
#define Error 0
#define OK 1
#define Infeasible -1
#define Overflow -2

typedef int Status;
typedef int ElemType;

#define List_int_size 100
#define Listincrement 100

typedef struct{
    ElemType*elem;
    int length;
    int listsize;//当前最大容量
}Sqlist;

Status Initlist_Sq(Sqlist &L);
Status Listinsert_Sq(Sqlist &L,int i, ElemType e);
Status Creat_Sq(Sqlist&L);
Status ListDelete_Sq(Sqlist &L, int i, ElemType &e);
int Locate_Sq(Sqlist &L, ElemType e);
Status Print_Sq(Sqlist L);
Status Sort_Sq(Sqlist &L);

int main(){
    ElemType e;
    Sqlist sq1;

    Initlist_Sq(sq1);
    Creat_Sq(sq1);
    printf("Sequence List is:\n");
    Print_Sq(sq1);

    e =100;
    Listinsert_Sq(sq1, 3, e);
    printf("Insert result is:\n");
    Print_Sq(sq1);

    ListDelete_Sq(sq1, 4, e);
    printf("Delete result is:\n");
    Print_Sq(sq1);

    e=100;
    printf("Element %d location: %d\n", e,  Locate_Sq(sq1, e));

    Sort_Sq(sq1);
    printf("Sort result is:\n");
    Print_Sq(sq1);
    return 0;
}

Status Initlist_Sq(Sqlist &L){
    L.elem = (ElemType*)malloc(List_int_size*sizeof(ElemType));
    if(!L.elem) exit (Overflow);
    L.length = 0;
    L.listsize = List_int_size;
    return OK;
}

Status Listinsert_Sq(Sqlist &L,int i, ElemType e){
    ElemType*newbase, *p, *q;
    if(i<1||i>L.length + 1) return Error;
    if(L.length >= L.listsize){
        newbase=(ElemType*)realloc(L.elem, (L.listsize+Listincrement)*sizeof(ElemType));
        if(!newbase) exit (Overflow);
        L.elem = newbase;
        L.listsize+=Listincrement;
    }
    q = &(L.elem[i-1]);
    for(p = &(L.elem[L.length-1]);p>=q;--p)*(p+1)=*p;
    *q=e;
    ++L.length;
    return OK;
}

Status Creat_Sq(Sqlist&L){
    ElemType temp;
    printf("Input Data(9999) ending:\n");
    scanf("%d", &temp);
    while(temp!= 9999){
        Listinsert_Sq(L, (L.length)+1, temp);
        printf("Input Data(9999) ending:\n");
        scanf("%d", &temp);
    }
    return OK;
}

Status ListDelete_Sq(Sqlist &L, int i, ElemType &e){
    ElemType *p, *q;
    if((i>L.length)||(i<1))return Error;
    p = &(L.elem[i-1]);
    e = *p;
    q = &(L.elem[L.length-1]);
    for(++p; p<=q; ++p) *(p-1)=*p;
    --L.length;
    return OK;
}

int Locate_Sq(Sqlist &L, ElemType e){
    ElemType*q;
    int i;
    for(i = 0;i < L.length;i++)
     if(L.elem[i] == e) return i+1;
    return 0;
}

Status Print_Sq(Sqlist L){
    int i;
    for(i = 0;i<L.length;i++)
        printf("%d\t", L.elem[i]);
    printf("\n");
    return OK;
}

Status Sort_Sq(Sqlist &L){
    int temp;
    for(int i = 0;i<L.length-1;i++){
        for(int j = i+1;j<L.length;j++){
            if(L.elem[i]>L.elem[j]){
                temp = L.elem[i];L.elem[i] = L.elem[j];L.elem[j] = temp;
            }
        }
    }
}

