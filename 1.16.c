#include <stdio.h>

int main(){
        int n1, n2;

        printf("请输入两个正整数：\n");
        printf("第一个数：\n");
        scanf("%d",&n1);

        printf("第二个数：\n");
        scanf("%d",&n2);

        printf("结果是:");

        int sum = n1 + n2;
        printf("和为%d\n",sum);

        int difference;
        if (n1 >= n2){
           difference = n1 - n2;
           printf("差为%d\n",difference);
        }else{
           difference = n2 - n1;
           printf("差为%d\n",difference);
        }

        int p = n1 * n2;
        printf("积为%d\n",p);

        if (n2 != 0){
           int q = n1 / n2;
           int r = n1 % n2;
           printf("商为%d，余%d\n",q,r);
        }else{
                printf("余数不为零！！！！！！！！");
        }
}
