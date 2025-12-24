#include <stdio.h>

int main()
{
    int a, b, c, min;
    printf("请输入三个数字：");
    scanf("%d %d %d",&a, &b, &c);

    if(a <= b && a<=c)
    {
        min = a;
    }else if(b <= a&&b <= c){
            min = b;
    }else{
            min = c;
    }
    printf("最小的是：%d\n",min);
}
