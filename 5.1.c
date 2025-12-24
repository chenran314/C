#include<stdio.h>

int leapyear(int y)//判断闰年
{
        if((y%4==0&&y%100!=0)||(y%400==0))
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

int thedayofmonth(int y,int m)//判断这一年里每个月日子多少
{
        switch(m)
        {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                        return 31;
                        break;
                case 4:
                case 6:
                case 9:
                case 11:
                        return 30;
                        break;
                case 2:
                        return leapyear(y)?29:28;
                        break;

                default:
                        printf("哪有这个月份？");
        }
}

int allthedays(int y,int m,int d)//计算日期差
{
        int days1=0,days2=0;
        for(int i=1;i<y;i++)
        {
                days1+=leapyear(i)?366:365;
        }
        for(int j=1;j<m;j++)
        {
                days1+=thedayofmonth(y,j);
        }
        days1+=d;//输入的日期和基准日期差的日期数

        for(int i=1;i<2025;i++)
        {
                days2+=leapyear(i)?366:365;
        }
        for(int j=1;j<11;j++)
        {
                days2+=thedayofmonth(2025,j);
        }
        days2+=12;//2025年11月12日和基准日期差的日期数

        return days1-days2;
}



int main()
{
        int y,m,d,all,b;
        printf("请输入日子的信息：（年月日以空格隔开）");
        scanf("%d %d %d",&y,&m,&d);
        all=allthedays(y,m,d);
        b=(all%7+7)%7;//防止负数出错
        switch(b)
        {
                case 0:
                        printf("周三\n");
                        break;
                case 1:
                        printf("周四\n");
                        break;
                case 2:
                        printf("周五\n");
                        break;
                case 3:
                        printf("周六\n");
                        break;
                case 4:
                        printf("周天\n");
                        break;
                case 5:
                        printf("周一\n");
                        break;
                case 6:
                        printf("周二\n");
                        break;
        }
        return 0;
}


