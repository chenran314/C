#include<stdio.h>
#include<stdlib.h>

#define r 15
#define c 15
#define e 0
#define ai 2
#define player 1

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
                        else if(bo[j][k]==ai)
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

int check(int bo[r][c],int x,int y, int side)//判断是否胜利的函数
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
                        if(nx>=0&&nx<=r&&ny>=0&&ny<=c&&bo[nx][ny]==side)//保证检查的棋子在>棋盘里
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
                        if(nx>=0&&nx<r&&ny>=0&&ny<c&&bo[nx][ny]==side)
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

int score(int bo[r][c],int x,int y, int side)//帮助AI下棋的函数
{
        if (bo[x][y]!=e)//有棋了，无效位置算是
                return -1;
        int dia[4][2]={{0,1},{1,0},{1,1},{1,-1}};
        int ms=0;
        for(int d=0;d<4;d++)
        {
                int dx=dia[d][0];
                int dy=dia[d][1];
                int same=0;//计算同色棋子的数量
                int block=0;//计算被异色棋子/边界阻挡的数量
                for(int j=1;j<5;j++)
                {
                        int nx=x+dx*j;
                        int ny=y+dy*j;
                        if(nx>=0&&nx<r&&ny>=0&&ny<c)
                        {
                                if(bo[nx][ny]==side)//side是区分阵营的
                                {
                                        same++;
                                }
                                else if(bo[nx][ny]==(side==player?ai:player))
                                {
                                        block++;
                                        break;
                                }
                                else
                                {
                                        break;
                                }
                        }
                        else
                        {
                                block++;
                                break;
                        }
                }

                for(int k=1;k<5;k++)
                {
                        int nx=x-dx*k;
                        int ny=y-dy*k;
                        if(nx>=0&&nx<r&&ny>=0&&ny<c)
                        {
                                if(bo[nx][ny]==side)
                                {
                                        same++;
                                }
                                else if(bo[nx][ny]==(side==player?ai:player))
                                {
                                        block++;
                                        break;
                                }
                                else
                                {
                                        break;
                                }
                        }
                        else
                        {
                                block++;
                                break;
                        }
                }
                int s=0;
                if(same>=4)//马上赢了
                        s=5;
                else if(same==3&&block==0)
                        s=4;//类似于空0000空
                else if(same==3&&block==1)
                        s=3;//类似于10000空
                else if(same==2&&block==0)
                        s=3;//类似于空000空
                else if(same==2&&block==1)
                        s=1;//类似于1000空
                else if(same==1&&block==0)
                        s=1;//类似于空00空

                if(s>ms)
                        ms=s;
        }
        return ms;
}
void move(int bo[r][c])
{
        int ms=-1;
        int bx=(r+1)/2,by=(r+1)/2;//开始在天元

        for(int x=0;x<r;x++)//遍历棋盘算分数
        {
                for(int y=0;y<c;y++)
                {
                        if(bo[x][y]!=e)
                        {
                                continue;
                        }
                        int ds=score(bo,x,y,player);//计算玩家每个棋子的分数
                        int as=score(bo,x,y,ai);//计算AI自己的棋子分数
                        int cs=(ds>as)?(ds+1):as;//加1提高防守优先级
                        if(cs>ms)
                        {
                                ms=cs;
                                bx=x;
                                by=y;
                        }
                }
        }
        bo[bx][by]=ai;
        printf("AI落子于%d行%d列\n",bx+1,by+1);
}
int main()
{
        int bo[r][c];
        int i,j,x,y,step=0;//黑子先行
        intboard(bo);

        while(1)//一直循环
        {
                draw(bo);
                printf("请玩家落子：（如7 8，指7行8列\n）");
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
                        printf("恭喜玩家获胜！！！\n");
                        break;
                }
                if(step>=r*c)//平局机制
                {
                        draw(bo);
                        printf("下满了，平局");
                        break;
                }
                printf("\nAI思考中...\n");
                move(bo);
                step++;
                int aix=-1,aiy=-1;
                for(i=0;i<r;i++)//找到AI刚下的位置
                {
                        for(j=0;j<c;j++)
                        {
                                if(bo[i][j]==ai&&(i!=x-1||j!=y-1))
                                {
                                        aix=i;
                                        aiy=j;
                                        break;
                                }
                        }
                }
                if(check(bo,aix,aiy,ai))
                {
                        draw(bo);
                        printf("菜\n");
                        break;
                }

        }
        return 0;
}
