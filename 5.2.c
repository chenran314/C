#include <stdio.h>

int leapyear(int y)
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

int thedayofmonth(int y,int m)
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

int allthedays(int y,int m,int d)
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
        days1+=d;

        for(int i=1;i<2025;i++)
        {
                days2+=leapyear(i)?366:365;
        }
        for(int j=1;j<11;j++)
        {
                days2+=thedayofmonth(2025,j);
        }
        days2+=12;

        return days1-days2;
}

int firstday(int y,int m)//找到这个月的第一天为周几
{
        int d1=allthedays(y,m,1);
        int b=(d1%7+7)%7;
        return b;
}

int main()
{
        int y,m,d,all,b;
        printf("请输入日子的信息：（年月以空格隔开）");
        scanf("%d %d",&y,&m);
        printf("日 一 二 三 四 五 六\n");
        int d1=firstday(y,m);//找1号为周几
        int dm=thedayofmonth(y,m);//找这个月一共多少号
        d1=(d1+3)%7;//5.1里的基准日期是周三，所以修正一下为周日
        for(int i=0;i<d1;i++)//打印日期前的空格
        {
                printf("   ");
        }
        for(int d=1;d<=dm;d++)//打印日期
        {
                printf("%2d ",d);//这里是2d而不是d
                if((d1+d)%7==0)//七个日子一换行
                {
                        printf("\n");
                }
        }
        printf("\n\n");
}
