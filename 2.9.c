#include <stdio.h>

int main()
{
        int n,i,j;
        printf("请输入一个奇数：");
        scanf("%d",&n);
        if(n%2==0)
        {
            printf("错误，芝士奇数吗？");
        }

        for(i=0;i<=n/2;i++)
        {
            for(j=0;j<n/2-i;j++)
            {
                printf(" ");
            }
            for(j=0;j<2*i+1;j++)
            {
                printf("*");
            }
            printf("\n");//查AI知道的换行命令
        }

        for(i=n/2-1;i>=0;i--)
        {
            for(j=0;j<n/2-i;j++)
            {
                    printf(" ");
            }
            for(j=0;j<2*i+1;j++)
            {
                    printf("*");
            }
            printf("\n");
        }
}
