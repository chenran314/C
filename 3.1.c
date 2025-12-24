#include <stdio.h>

int main()
{
        int A[10];
        int i,n;
        printf("请输入10个整数：");
        for(i=0;i<=9;i++)
        {
                printf("请输入第%d个整数",i+1);
                scanf("%d",&A[i]);
        }

        for(i=0;i<4;i++)
        {
                n=A[i];
                A[i]=A[9-i];
                A[9-i]=n;
        }
        printf("结果为：");
        for(i=0;i<10;i++)
        {
                printf("%d ",A[i]);
        }
                printf("\n");
}
