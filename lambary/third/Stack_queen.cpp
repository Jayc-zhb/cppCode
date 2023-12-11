#include<bits/stdc++.h>
using namespace std;

typedef int Status;
typedef int ElemType;

#define stack_int_size 100
#define stack_add 10

typedef struct {
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqstack;

Status initstack(sqstack &S);
Status pushstack(sqstack &S, ElemType e);
Status pop(sqstack &S, ElemType &e);
Status is_emptystack(sqstack S);
ElemType Gettop(sqstack S);
//----------------------------------------

#define queuesize 100

typedef struct {
    ElemType *base;
    int front, rear;
}sqquene;

Status initquene(sqquene &Q);
Status Enquene(sqquene &Q, ElemType e);
Status Dequene(sqquene &Q, ElemType &e);
ElemType Gethead(sqquene Q);
Status Q_traverse(sqquene Q);

//--------------------------------------

int main(){
    sqstack s; sqquene q;
    ElemType ch, e1, e2;
    int state;
    initstack(s);initquene(q);
    printf("Please input a string ending with '#':");
    while((ch = getchar())!= '#'){
        pushstack(s, ch);Enquene(q, ch);
    }
    printf("\nThe quene is :");
    Q_traverse(q);printf("\n");
    state = 1;
    while(!is_emptystack(s)&&state){
        if(Gettop(s) == Gethead(q)){
            pop(s, e1);Dequene(q, e2);
        }
        else state = 0;
    }
    if(state) printf("This stirng is Palindrom!\n");
    else   printf("This string is not Palindrom!\n");
    return 1;
}
//-------------Stack Operate-----------
Status initstack(sqstack &s){
    s.base = (ElemType *)malloc(stack_int_size*sizeof(ElemType));
    if(!s.base) exit(-2);
    s.top = s.base;
    s.stacksize = stack_int_size;
    return 1;
}

Status pushstack(sqstack &s, ElemType e){
    if(s.top - s.base>= s.stacksize){
        s.base = (ElemType*)realloc(s.base,( s.stacksize + stack_add)*sizeof(ElemType));
    if(!s.base) exit(-2);
    s.top = s.base + s.stacksize;
    s.stacksize += stack_add;
    }
    *(s.top++) = e;
    printf("s.base[%d] = %c\n", s.top-s.base -  1, e);
    return 1;
}
Status pop(sqstack &s, ElemType &e){
    if(s.top == s.base) return 0;
    e = *(--s.top);
    return 1;
}
Status is_emptystack(sqstack s){
    if(s.top == s.base)return 1;
    else return 0;
}
ElemType Gettop(sqstack s){
    ElemType e;
    if(s.top == s.base) exit(-2);
    e =*(s.top - 1);
    return e;
}

//------------Quene Operate-----------------

Status initquene(sqquene &Q){
    Q.base = (ElemType*)malloc(queuesize*sizeof(ElemType));
    if(!Q.base)exit(-2);
    Q.front = Q.rear = 0;
    return 1;
}
Status Enquene(sqquene &Q, ElemType e){
    if(Q.front == (Q.rear + 1)%queuesize){
        printf("Quene overflow");return 0;}
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1)%queuesize;
    return 1;
}
Status Dequene(sqquene &Q, ElemType &e){
    if(Q.front == Q.rear){
        printf("Queue empty");
        return 0;
        }
        e = Q.base[Q.front];
        Q.front = (Q.front + 1)%queuesize;
        return 1;
}
ElemType Gethead(sqquene Q){
    if(Q.front == Q.rear){
        printf("Queue empty");
        return 0;
    }
    else return Q.base[Q.front];
}
Status Q_traverse(sqquene Q){
    int p;
    if(Q.front == Q.rear){
        printf("Queue empty");
        return 0;
    }
    p = Q.front;
    do{
        (printf("%2c", Q.base[p]));
        p = (p + 1)%queuesize;
    }while(p!=Q.rear);
    return 1;
}
