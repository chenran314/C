#include<stdio.h>

void swap(int *x,int *y)
{
        int a;
        a=*x;
        *x=*y;
        *y=a;
}

int main()
{
        int a,b;
        printf("请输入两个整数：");
        scanf("%d %d",&a,&b);
        swap(&a,&b);
        printf("a的值为：%d,b的值为：%d",a,b);
}
