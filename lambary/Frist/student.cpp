#include<string.h>
#include<stdio.h>
#define FORMAT "%d\n%s\n%f\n%f\n%f\n"
struct student
{
    int num;
    char name[20];
    float scoer[3];
};

void print(struct student stu)
{
    printf(FORMAT, stu.num, stu.name, stu.scoer[0], stu.scoer[1], stu.scoer[2]);
    printf("\n");
}

int main(){
    struct student stu;
    stu.num = 12345;
    strcpy(stu.name, "Li Li");
    stu.scoer[0] = 67.5;
    stu.scoer[1] = 89;
    stu.scoer[2] = 78.5;
    printf("1.结果是:\n");
    print(stu);
    return 0;
}


