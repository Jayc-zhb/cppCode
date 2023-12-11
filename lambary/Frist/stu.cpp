#include<string.h>
#include<stdio.h>
#define FORMAT "%d\n%s\n%f\n%f\n%f\n"
struct student
{
    int num;
    char name[20];
    float scoer[3];
}stu = {12345, "Li Li", 67.5, 89, 78.5};

int main(){
    void print(struct student *);
    printf("2.结果是:\n");
    print(&stu);
    return 0;
}
void print(struct student *p)
{
    printf(FORMAT, p->num, p->name, p->scoer[0], p->scoer[1], p->scoer[2]);
    printf("\n");
}