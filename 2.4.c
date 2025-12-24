#include <stdio.h>

int main(){

    int n, i,sum=0;
    printf("请输入一个自然数：");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum=sum+i;
    }
    printf("累加结果是：%d",sum);
}
