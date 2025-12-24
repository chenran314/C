#include <stdio.h>

int s(char r[],int c)//计算每行的ASCII码总和
{
        int sum=0,i;
        for(i=0;i<c;i++)
        {
                sum=r[i]+sum;
        }
}

void paihangxu(char r[],int c)//排每行内元素的顺序
{
        int i,j;
        char m;
        for(i=0;i<c;i++)//之间抄我上次做的3.3.2的冒泡排序(*^ω^*)
        {
                for(j=c-1;j>0;j--)
                {
                        if(r[j]<r[j-1])
                        {
                                m=r[j];
                                r[j]=r[j-1];
                                r[j-1]=m;
                        }
                }
        }
}

void pailiexu(char a[][6],int r,int c)//排每一大列的顺序
{
        int i,j,k;
        char m;

        for(i=0;i<r;i++)//依旧control c+control v
        {
                for(j=r-1;j>0;j--)
                {
                        if(s(a[j],c) < s(a[j-1],c))
                        {
                                for(k=0;k<c;k++)                               {
                                        m=a[j][k];
                                        a[j][k]=a[j-1][k];
                                        a[j-1][k]=m;
                                }
                        }
                }
        }
}

int main()
{
        char b[][6]=
        {
                {'S','D','U','Y','E','S'},
                {'C','H','I','N','A','!'},
                {'A','F','T','E','R','X'},
                {'h','e','r','o','a','b'},
                {'C','y','y','D','S','!'},
        };
        int r=5,c=6;

        int i,j;
        for(i=0;i<c;i++)
        {
                paihangxu(b[i],c);
        }

        pailiexu(b,r,c);

        printf("\n结果是：\n");
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf(" %c ",b[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
