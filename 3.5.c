#include<stdio.h>

int two_dim_array_access(int *x, int i, int j, int m, int n, int C)
{
        int a=(m-i)*C+(n-j);
        int b=*(x+a);
        printf("A[%d][%d]=%d",m,n,b);
        printf("\n");
}

int main()
{
        int A[2][3]={{1,2,3},{4,5,6}};
        two_dim_array_access(&A[0][0],0,0,1,2,3);
        two_dim_array_access(&A[0][1],0,1,1,2,3);
}
