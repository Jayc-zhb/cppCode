#include<stdio.h>

void input(int a[], int n);
void choose(int a[], int n);
int main(void){
    int n, a[100];
    printf("请输入你要输入的整数:");
    scanf("%d", &n);
    printf("输入%d个数组元素:", n);
    input(a, n);
    choose(a, n);
    for(int i = 0;i < n;i++){
        printf("%d ", a[i]);
    }
    
}

void input(int a[], int n){
    for(int i = 0;i < n;i++){
        scanf("%d", &a[i]);
    }
}
void choose(int a[], int n){
    int i, j, k, t;
    for(i = 0;i<n-1;i++){
        k = i;
        for(j = i+1;j<n;j++)         //比较大小，记录最小元素的下标 
            if(a[j]<a[k]) k = j; 
        t = a[i], a[i] = a[k], a[k] = t;    //交换最小元素与a[i]的值
    }
}