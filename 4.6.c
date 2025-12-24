#include<stdio.h>

struct student
{
        char name[20];
        int score;
};

int main()
{
        struct student stu[3];
        struct student *p;
        struct student *max;
        for(p=stu;p<stu+3;p++)
        {
                printf("请输入第%d个学生的姓名和成绩：",(int)(p-stu)+1);
                scanf("%s %d",p->name,&(p->score));
        }


        printf("姓名\t成绩\n");
        for(p=stu;p<stu+3;p++)
        {
                printf("%s\t%d\n",p->name,p->score);
        }

        max=stu;
        for(p=stu+1;p<stu+3;p++)
        {
                if(p->score>max->score)
                {
                        max=p;
                }
        }

        printf("分数最高的学生为：%s，成绩为：%d",max->name,max->score);
}
