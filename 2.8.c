#include <stdio.h>

int main()
{
        int n,m=0;
        printf("请输入正整数：");
        scanf("%d",&n);
        while(n!=0)
        {
                m=m*10+n%10;
                n=n/10;
        }
                printf("%d",m);

}
