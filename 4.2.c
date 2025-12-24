#include<stdio.h>

int main()
{
        int a[5]={1,2,3,4,5},i;
        int *p;
        for(i=0;i<5;i++)
        {
                p=&a[i];
                printf("a[i]的值为：%d，a[i]的地址为：%p\n",*p,p);
        }
}
