#include <stdio.h>

int main()
{
        int n,sum=0,i=1;
        printf("请输入正整数：");
        scanf("%d",&n);

        do
        {
                sum=sum+i;
                i=i+2;
        }while(i<=n);
        printf("结果是：%d\n",sum);
        return 0;
}
