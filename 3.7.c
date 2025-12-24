#include <stdio.h>

void matrix_multi(double a[3][4],double b[4][5], double c[3][5])
{
        int i,j,k;
        for(i=0;i<3;i++)
        {
                for(j=0;j<5;j++)
                {
                        for(k=0;k<4;k++)
                        {
                                c[i][j]+=a[i][k]+b[k][j];
                        }
                }
        }
}

int main()
{
        double a[3][4]=
        {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12},
        };
        double b[4][5]=
        {
                {1,1,4,5,1},
                {4,1,9,1,9},
                {8,1,0,1,2},
                {3,4,5,6,7},
        };
        double c[3][5];  
        matrix_multi(a,b,c);
        for (int i=0;i<3;i++)
        {
                for (int j=0;j<5;j++)
                {
                        printf("%f  ",c[i][j]);
                }
                printf("\n");
        }
}
