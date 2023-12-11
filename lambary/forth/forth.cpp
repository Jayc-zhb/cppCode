#include <stdio.h>                            
#include <stdlib.h>                           
#include <string.h>                           
#define TRUE 1                                
#define FALSE 0                               
#define OK 1                                  
#define ERROR 0                               
#define INFEASIBLE -1                         
#define OVERFLOW -2                           
typedef int Status;                           
#define MAXSTRLEN 255                         
typedef unsigned char SString[MAXSTRLEN + 1]; 

Status StrAssign(SString &S, char *chars)
{
    int i, j; 
    char *c;  
    for (i = 0, c = chars; *c; ++i, ++c)
        ;              
    if (i > MAXSTRLEN) 
        return ERROR;  
    else
    {
        S[0] = i;                    
        for (j = 1; j <= S[0]; j++)  
            S[j] = *(chars + j - 1); 
    }
    return OK; 
}

int StrLength(SString S)
{
    return S[0]; 
}

void StrPrint(SString S)
{
    int i;                      
    for (i = 1; i <= S[0]; i++) 
        printf("%c", S[i]);     
                                
}

Status SubString(SString &Sub, SString S, int pos, int len)
{
    
    int i; 
    if (pos < 1 || pos > S[0] || len < 0 || len > S[0] - pos + 1)
    {
        printf("λ�÷Ƿ�\n"); 
        return ERROR;         
    }
    for (i = 1; i <= len; i++)
        Sub[i] = S[pos + i - 1]; 
    Sub[0] = len;                
    return OK;                   
}

Status Concat(SString &T, SString S1, SString S2)
{
    
    
    int i; 
    if (S1[0] + S2[0] <= MAXSTRLEN)
    {
        
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i]; 
        for (i = 1; i <= S2[0]; i++)
            T[S1[0] + i] = S2[i]; 
        T[0] = S1[0] + S2[0];     
        return TRUE;              
    }
    else
    {
        
        for (i = 1; i <= S1[0]; i++)
            T[i] = S1[i]; 
        for (i = 1; i <= MAXSTRLEN - S1[0]; i++)
            T[S1[0] + i] = S2[i]; 
        T[0] = MAXSTRLEN;         
        return FALSE;             
    }
}

int StrCompare(SString S, SString T)
{
    
    int i; 
    for (i = 1; i <= S[0] && i <= T[0]; ++i)
    {
        if (S[i] != T[i])
            return (S[i] - T[i]); 
    }
    return (S[0] - T[0]); 
}

int Index(SString s1, SString s2, int pos)
{
    
    int i, j; 
    if (pos < 1 || pos > s1[0])
    {
        printf("ƥ����ʼλ�÷Ƿ�\n"); 
        exit(0);                      
    }
    i = pos; 
    j = 1;   
    while (i <= s1[0] && j <= s2[0])
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++; 
        }
        else
        {
            i = i - j + 2;
            j = 1; 
        }
    }
    if (j > s2[0])
        return i - j + 1; 
    else
        return 0; 
}
int main()
{
    int i, j, opp = 1;           
    int pos;                     
    char s;                      
    char chars1[50], chars2[50]; 
    SString t, s1, s2, sub;      
    Status k;                    
    printf("\n 1, StrAssign ���ɴ�\n 2, StrLength �󴮳� ");
    printf("\n 3, StrCompare ���Ƚ�\n 4, Concat ������");
    printf("\n 5, SubString ���Ӵ�\n 6, Index ��ƥ��");
    printf("\n 0, �˳�\n");
    printf("��ѡ����Ĳ���:\n"); 
    while (opp != 0)
    {                        
        scanf_s("%d", &opp); 
        getchar();           
        switch (opp)
        {                               
        case 1:                         
            printf("Please input s1:"); 
            if (fgets(chars1, sizeof(chars1), stdin) != NULL)
            {
                size_t len = strlen(chars1);
                if (len > 0 && chars1[len - 1] == '\n')
                {
                    chars1[len - 1] = '\0'; 
                    len--;                  
                }
            }
            k = StrAssign(s1, chars1); 
            if (!k)
            {                                       
                printf("�������� %d\n", MAXSTRLEN); 
                exit(0);                            
            }
            printf("��s1Ϊ��");                   
            StrPrint(s1);                         
            printf("\n");                         
            break;                                
        case 2:                                   
            printf("����Ϊ %d\n", StrLength(s1)); 
            break;                                
        case 3:                                   
            printf("Please input s2:");           
            if (fgets(chars2, sizeof(chars2), stdin) != NULL)
            { 
                size_t len = strlen(chars2);
                if (len > 0 && chars2[len - 1] == '\n')
                {
                    chars2[len - 1] = '\0'; 
                    len--;                  
                }
            }
            k = StrAssign(s2, chars2); 
            if (!k)
            {                                       
                printf("�������� %d\n", MAXSTRLEN); 
                exit(0);                            
            }
            printf("��s2Ϊ��");     
            StrPrint(s2);           
            printf("\n");           
            i = StrCompare(s1, s2); 
            if (i < 0)
                s = '<'; 
            else if (i == 0)
                s = '='; 
            else
                s = '>';                                  
            printf("��s1 %c ��s2\n", s);                  
            break;                                        
        case 4:                                           
            Concat(t, s1, s2);                            
            StrPrint(t);
            printf("\n");                                  
            break;                                        
        case 5:                                           
            printf("��s1���Ӵ����������Ӵ���ʼλ�ã�"); 
            scanf_s("%d", &i);                            
            printf("�������Ӵ��ĳ��ȣ�");                 
            scanf_s("%d", &j);                            
            printf("��ʼλ�ã�%d, �Ӵ����ȣ�%d", i, j);   
            k = SubString(sub, s1, i, j);                 
            if (k){                          
                printf("�Ӵ�subΪ��"); 
                StrPrint(sub);         
            }
            printf("\n");
            break;                      
        case 6:                         
            int wz[80];      
            i = 0;                      
            printf("Please input s1:"); 
            if (fgets(chars1, sizeof(chars1), stdin) != NULL)
            {
                size_t len = strlen(chars1);
                if (len > 0 && chars1[len - 1] == '\n')
                {
                    chars1[len - 1] = '\0'; 
                    len--;                  
                }
            }
            k = StrAssign(s1, chars1); 
            if (!k)
            {                                       
                printf("�������� %d\n", MAXSTRLEN); 
                exit(0);                            
            }
            printf("Please input s2:"); 

            if (fgets(chars2, sizeof(chars2), stdin) != NULL)
            {
                size_t len = strlen(chars2);
                if (len > 0 && chars2[len - 1] == '\n')
                {
                    chars2[len - 1] = '\0'; 
                    len--;                  
                }
            }
            k = StrAssign(s2, chars2); 
            if (!k)
            {                                       
                printf("�������� %d\n", MAXSTRLEN); 
                exit(0);                            
            }
            pos = 1; 
            while (pos <= s1[0])
            {                           
                j = Index(s1, s2, pos); 
                if (j < 1)
                    break; 
                else
                {
                    i++;             
                    wz[i] = j;       
                    pos = j + s2[0]; 
                }
            }
            if (i == 0)
                printf("û�м�������Ҫ���Ӵ���"); 
            else
            {
                printf("�Ӵ��������г��� %d ��\n", i); 
                printf("%d ��ƥ���λ�÷ֱ�Ϊ:", i);   
                for (k = 1; k <= i; k++)
                    printf("%4d", wz[k]); 
            }
            printf("\n"); 
            break;        
        case 0:           
            exit(0);      
        }
        printf("��ѡ����Ĳ���:\n"); 
    }
    return 0;
}