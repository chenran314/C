#include <stdio.h>

int main()
{
        int n,i=1,s=0;
        printf("请输入一个正整数：");
        scanf("%d",&n);

        if(n<=1)
        {
                s=1;
        }else
        {
        for(i=2;i<n;i++)
        {
                if(n%i==0)
                {
                        s=1;
                break;
                }
        }
        }
        if(s==1)
        {
                printf("no");
        }else{
                printf("yes");
        }
}
