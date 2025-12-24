#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "seat_status.data"

int zuo[10][10];

void chushihua();
void zhanshi();
void xuanzuo();
void baocun();



int main()
{
        int a;
        chushihua();
        while(1)
        {
                printf("\n1.查看座位表 2.预定座位 3.退出系统\n");
                printf("请输入功能编号：\n");
                scanf("%d",&a);
                switch(a)
                {
                        case 1:
                                zhanshi();
                                break;
                        case 2:
                                xuanzuo();
                                break;
                        case 3:
                                baocun();
                                printf("感谢使用！再见！\n");
                                return 0;
                        default:
                                printf("输入错误，请重试！\n");
                }
        }
}



void chushihua()
{
        FILE*fp=fopen(FILE_NAME,"rb");

        if(fp!=NULL)
        {
                fread(zuo,sizeof(int),10*10,fp);
                fclose(fp);
                printf("座位状态加载成功！\n");
        }
        else
        {
                for(int i=0;i<10;i++)
                {
                        for(int j=0;j<10;j++)
                        {
                                zuo[i][j]=0;
                        }
                }
        }
}

void zhanshi()
{
        printf("        大荧幕\n");
        printf("   1 2 3 4 5 6 7 8 9 10\n");
        for(int i=0;i<10;i++)
        {
                printf("%2d ",i+1);
                for(int j=0;j<10;j++)
                {
                        if(zuo[i][j]==0)
                        {
                                printf("□ ");
                        }
                        else
                        {
                                printf("■ ");
                        }
                }
                printf("\n");
        }
}

void xuanzuo()
{
        int a,i,x,y;
        float zongji=0.0,jia=49.9;
        printf("请选择订票数量：\n");
        scanf("%d",&a);
        for(i=1;i<=a;i++)
        {
                while(1)
                {
                        printf("请选择第%d张票的位置：（例:3 5代表3行5列）\n",i);
                        scanf("%d %d",&x,&y);
                        if(zuo[x-1][y-1]!=0)
                        {
                                printf("错误的预定位置！\n");
                                continue;
                        }
                        else
                        {
                                zuo[x-1][y-1]=1;
                                jia=49.9;
                                zongji+=jia;
                                printf("第%d张票已预定完成，座位：%d行%d列，票价：%0.1f\n",i,x,y,jia);
                                break;
                        }
                }
        }
        printf("你的%d张票已全部预定完成，总价%0.1f元\n",a,zongji);
        baocun();
}

void baocun()
{
        FILE*fp=fopen(FILE_NAME,"wb");

        if(fp!=NULL)
        {
                fwrite(zuo,sizeof(int),10*10,fp);
                fclose(fp);
        }
        else
        {
                printf("警告：座位状态保存失败！下次启动可能丢失数据\n");
        }
}
