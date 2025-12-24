#include <stdio.h>

int main()
{
        int n,i,j,s;
        printf("请输入一个正整数：");
        scanf("%d",&n);
        printf("1到%d范围内的素数：\n",n);

        for(i=2;i<=n;i++)
        {
            s=1;
            for(j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    s=0;
                    break;
                }
            }
            if(s==1)
            {
                printf("%d",i);
            }
            printf("\n");
        }
        return 0;
}
