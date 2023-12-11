#include <bits/stdc++.h>
using namespace std;
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
#define MAXSIZE 100
typedef struct
{
    int i, j;
    ElemType e;
} Triple;
typedef struct
{
    Triple *data;
    int mu, nu, tu;
} TSMatrix;
Status InitMatrix_Th(TSMatrix *M)
{
    M->data = (Triple *)malloc((MAXSIZE + 1) * sizeof(Triple));
    if (M->data == NULL)
        return ERROR;
    M->mu = 0;
    M->nu = 0;
    M->tu = 0;
    return OK;
}
Status CreatMatrix(TSMatrix *M)
{
    int t;
    InitMatrix_Th(M);
    cout << "****************欢迎进入转置系统****************\n"
         << '\n';
    cout << "输入稀疏矩阵的行数、列数和非零元素个数:\n";
    cin >> M->mu >> M->nu >> M->tu;
    if (M->tu == 0)
        return ERROR;
    cout << "按行序输入" << M->tu << "个非零元素的三元组:\n";
    for (t = 1; t <= M->tu; t++)
    {
        cout << "输入第" << t << "个非零元素的行号、列号和值:\n";
        cin >> M->data[t].i >> M->data[t].j >> M->data[t].e;
    }
    return OK;
}
Status FastTransMatrix(TSMatrix M, TSMatrix *T)
{
    int col, t, p, q;
    int num[MAXSIZE], cpot[MAXSIZE];
    InitMatrix_Th(T);
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    if (T->tu)
    {
        for (col = 1; col <= M.nu; col++)
            num[col] = 0;
        for (t = 1; t <= M.tu; t++)
            ++num[M.data[t].j];
        cpot[1] = 1;
        for (col = 2; col <= M.nu; col++)
            cpot[col] = cpot[col - 1] + num[col - 1];
        for (p = 1; p <= M.tu; p++)
        {
            col = M.data[p].j;
            q = cpot[col];
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}
Status OutputMatrix(TSMatrix M)
{
    int t;
    cout << M.mu << "行 " << M.nu << "列 " << M.tu << "个非零元素\n";
    cout << "各非零元分别为:\n";
    for (t = 1; t <= M.tu; t++)
        printf("%d %d %d\n", M.data[t].i, M.data[t].j, M.data[t].e);
    cout << M.data[t].i << ' ' << M.data[t].j << ' ' << M.data[t].e << '\n';
    return OK;
}
Status PrintMatrix(TSMatrix M)
{
    int row, col, k;
    int a[10][10] = {0};
    for (k = 1; k <= M.tu; k++)
        a[M.data[k].i][M.data[k].j] = M.data[k].e;
    for (row = 1; row <= M.mu; row++)
    {
        for (col = 1; col <= M.nu; col++)
            cout << a[row][col] << ' ';
        cout << '\n';
    }
    return OK;
}

int main()
{
    TSMatrix M;
    TSMatrix T;
    CreatMatrix(&M);
    cout << "\n原始矩阵M为:";
    OutputMatrix(M);
    cout << "\n原始矩阵M阵列为:\n";
    PrintMatrix(M);
    FastTransMatrix(M, &T);
    cout << "\n转置矩阵T为:";
    OutputMatrix(T);
    cout << "\n转置矩阵T阵列为:\n";
    PrintMatrix(T);
    free(M.data);
    free(T.data);
    return 0;
}