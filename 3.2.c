#include <stdio.h>

int main()
{
        int A[10];
        int i,j,n=0;
        printf("请输入10个范围在0-9之间的整数");
        for(i=0;i<10;i++)
        {
                printf("请输入第%d个整数：",i+1);
                scanf("%d",&A[i]);
        }

        for(j=1;j<11;j++)
        {
                for(i=0;i<10;i++)
                {
                        if(A[i]==j)
                        {
                        n++;
                        }
                }
                printf("整数%d出现了%d次",j,n);
                printf("\n");
                n=0;
   
