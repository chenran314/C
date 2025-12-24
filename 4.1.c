#include<stdio.h>

int main()
{
        int a,b=1;
        int *p=NULL;
        p=&a;
        printf("a的值为：%d，a的地址为%p\n",a,&a);
        printf("p的值为：%p，*p的值为%d\n",&p,*p);
        p=&b;
        *p+=10;
        printf("b为：%d\n",b);
}
