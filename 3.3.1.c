#include<stdio.h>

int main()
{
        int A[10];
        int i,j,n,m;
        printf("请输入10个整数");
        for(i=0;i<10;i++)
        {
                printf("请输入第%d个整数：",i+1);
                scanf("%d",&A[i]);
        }

        for(i=0;i<9;i++)
        {
                m=A[i];//假设一个最小的数
                n=i;//确定这个数的位置
                for(j=i+1;j<10;j++)
                {
                        if(A[j]<m)//判断后面的数和它的大小关系
                        {
                                m=A[j];//修订最小的数
                                n=j;//修订最小的数的位置
                        }
                }
                A[n]=A[i];//将实际最小的、数与当前排序的数交换
                A[i]=m;
        }

        printf("从小到大排序结果为：\n");
        for(i=0;i<10;i++)
        {
                printf("%d ",A[i]);
        }
}
