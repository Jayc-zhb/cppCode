#include"stdio.h"

void selectSort(int *p, int n)  //选择排序
{
    int i, j, *pt, temp;
    for(i = 0;i<n;i++)
    {
        pt = p + i;    //当前指针位置
        for(j = i+1;j<n;j++){
            if(*(p+j)<*pt) pt = p + j;//记录最小数组元素位置
        }
        temp = *pt, *pt = *(p + i), *(p + i) = temp; //将范围内最小元素交换到i位置
    }
}

void insertSort(int *p, int n)  //插入排序
{
    int i, j, temp;
    for(i = 1;i < n;i++)
    {
        temp = *(p + i);
        for(j = i - 1;j >=0 && temp <*(p + j);j --)
            *(p + j + 1) = *(p + j); //将大于temp的元素循环向后移
        *(p + j + 1) = temp;
    }
}

void bubbleSort(int *p, int n)//冒泡排序
{
    int i, j, temp;
    for(i = n-1;i >= 0;i--){
        for(j = 0;j <= i-1;j++){
            if(*(p+j)>*(p+j+1)){
                temp = *(p+j),*(p+j) = *(p+j+1); *(p+j+1) = temp;
            }
        }
    }
}
int main(){
    int a[10] = {99, 54, 25, 66, 23, 65, 43, 76, 84, 34};
    printf("排序前：");
    for(int i = 0;i < 10;i++)printf("%d ", a[i]);
    printf("\n开始排序.................\n");
    bubbleSort(a, 10);
    // insertSort(a, 10);
    // selectSort(a, 10);
    printf("排序后:");
    for(int i = 0;i < 10;i++)printf("%d ", a[i]);
    return 0;
}