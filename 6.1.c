#include<stdio.h>
#include<stdlib.h>

#define r 15
#define c 15
#define e 0
#define w 2
#define b 1

void intboard(int bo[r][c])//初始化棋盘的函数
{
        for(int i=0;i<r;i++)
        {
                for(int j=0;j<c;j++)
                {
                        bo[i][j]=0;
                }
        }
}

void draw(int bo[r][c])//每下一次刷新一次棋盘的函数
{
        printf("    ");
        for(int i=1;i<=r;i++)
        {
                printf("%2d ",i);
        }
        printf("\n");
        for(int j=0;j<r;j++)
        {
                printf("%2d ",j+1);
        for(int k=0;k<c;k++)
                {
                        if(bo[j][k]==e)
                        {
                                printf("  +");
                        }
                        else if(bo[j][k]==w)
                        {
                                printf("  ●");//代表白方
                        }
                        else
                        {
                                printf("  ○");//代表黑方
                        }
                }
                printf("\n");
        }

}

int check(int bo[r][c],int x,int y, int player)//判断是否胜利的函数
{
        int dia[4][2]={{0,1},{1,0},{1,1},{1,-1}};//4个方向，右、上、右上、右下
        for(int i=0;i<4;i++)
        {
                int n=1;
                int dx=dia[i][0];
                int dy=dia[i][1];
                for(int j=1;j<5;j++)//检查此方向上的4颗棋子
                {
                        int nx=x+dx*j;
                        int ny=y+dy*j;
                        if(nx>=0&&nx<=r&&ny>=0&&ny<=c&&bo[nx][ny]==player)//保证检查的棋子>在棋盘里
                        {
                                n++;
                        }
                        else
                        {
                                break;
                        }
                }
                for(int j=1;j<5;j++)//检查反方向（左、下、左下、左上）上的4颗棋子
                {
                        int nx=x-dx*j;
                        int ny=y-dy*j;
                        if(nx>=0&&nx<r&&ny>=0&&ny<c&&bo[nx][ny]==player)
                        {
                                n++;
                        }
                        else
                        {
                                break;
                        }
                }
                if(n>=5)
                {
                        return 1;//连成五子胜利
                }
        }
        return 0;//未胜利
}



int main()
{
        int bo[r][c];
        int i,j,x,y,player=b,step=0;//黑子先行
        intboard(bo);

        while(1)//一直循环
        {
                draw(bo);
                printf("请%d号玩家落子：（如7 8，指7行8列\n）",player);
                scanf("%d %d",&x,&y);
                if(x==0&&y==0)//退出机制
                {
                        printf("已退出游戏\n");
                        exit(0);
                }
                if(bo[x-1][y-1]!=e)
                {
                        printf("怎么下的棋？下我棋上了！\n");
                        continue;
                }

                bo[x-1][y-1]=player;
                step++;
                if(check(bo,x-1,y-1,player))//获胜机制
                {
                        draw(bo);
                        printf("恭喜%d号玩家获胜！！！\n",player);
                        break;
                }
                if(step>=r*c)//平局机制
                {
                        draw(bo);
                        printf("下满了，平局");
                        break;
                }
                player=(player==1)?2:1;//换人下棋
        }
        return 0;
}



