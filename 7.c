#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct student
{
        char id[20];
        char name[20];
        float score;
}student;
struct student stu[100];

int len=0;//储存个数
int maxlen=100;//最大储存个数
const char*DATA_FILE="student_data.txt";//储存的数据的文件路径
struct student*students=NULL;

int xuehao(char* id)
{
        for(int i=0;i<len;i++)//遍历所有已录入的学生
        {
                if(strcmp(stu[i].id,id)==0)//比较两个学号是否相同
                {
                        return i;
                }
        }
        return -1;
}

void xianshi();
void luru()
{
        int n;
        printf("请输入录入学生数目：\n");
        scanf("%d",&n);
        getchar();

        for(int i=0;i<n;i++)
        {
                printf("录入第%d个学生信息：\n",i+1);
                student*s=&stu[len];

                while(1)//防止学号录入重复
                {
                        printf("请输入学号：");
                        fgets(s->id,20,stdin);//避免数组溢出，可读取含空格的数据
                        s->id[strcspn(s->id,"\n")]='\0';//fgets函数会读取回车键，这个可将\n转化为\0
                        if(xuehao(s->id)!=-1)
                        {
                                printf("该学号已被录入\n");
                        }
                        else
                        {
                                break;
                        }
                }

                printf("请输入姓名：");
                fgets(s->name,20,stdin);
                s->name[strcspn(s->name,"\n")]='\0';

                printf("请输入成绩：\n");
                scanf("%f",&s->score);
                getchar();
                len++;
        }
        printf("\n已录入完成！目前已经储存%d名学生！\n",len);
}

void chaxun()
{
        int a;
        printf("\n选择查询方式：\n");
        printf("\n按学号查询请按1，按姓名查询请按2\n");
        scanf("%d",&a);
        getchar();

        if(a==1)
        {
                char id[20];
                printf("请输入学号：\n");
                fgets(id,20,stdin);
                id[strcspn(id,"\n")]='\0';
                int b=xuehao(id);
                if(b==-1)
                {
                        printf("查无此人\n");
                        return;
                }
                student*s=&stu[b];
                printf("学号：%s\n",s->id);
                printf("姓名：%s\n",s->name);
                printf("成绩：%f\n",s->score);
        }
        else if(a==2)
        {
                char name[20];
                printf("请输入姓名：");
                fgets(name,20,stdin);
                name[strcspn(name,"\n")]='\0';
                int c=0;
                for(int i=0;i<len;i++)
                {
                        student*s=&stu[i];
                        if(strstr(s->name,name)!=NULL)
                        {
                                printf("第%d名学生：\n",++c);
                                printf("学号：%s\n",s->id);
                                printf("姓名：%s\n",s->name);
                                printf("成绩：%f\n",s->score);
                        }
                }
                if(c==0)
                {
                        printf("查无此人\n");
                }
        }
        else
        {
                printf("查询方式错误！\n");
        }
}

void paixu()
{
        if(len<=1)
        {
                printf("一个还排？\n");
        }

        int xuanze,a;
        printf("\n选择排序方式：\n");
        printf("\n按学号排序请按1，按成绩排序请按2\n");
        scanf("%d",&xuanze);

        for(int i=0;i<len-1;i++)//冒泡排序
        {
                for(int j=0;j<len-1-i;j++)
                {
                        if(xuanze==1)
                        {
                                if(strcmp(stu[j].id,stu[j+1].id)>0)
                                {
                                        struct student a;
                                        a=stu[j];
                                        stu[j]=stu[j+1];
                                        stu[j+1]=a;
                                }
                        }
                        else if(xuanze==2)
                        {
                                if(stu[j].score<stu[j+1].score)
                                {
                                        struct student a;
                                        a=stu[j];
                                        stu[j]=stu[j+1];
                                        stu[j+1]=a;
                                }
                        }
                }
        }
        printf("已排序完成！\n");
        xianshi();
}

void tongji()
{
        if(len==0)
        {
                printf("没人统计啥？");
                return;
        }
        float gao=stu[0].score;
        float di=stu[0].score;
        int jige=0;
        float jun=0;

        for(int i=0;i<len;i++)
        {
                student*s=&stu[i];
                jun+=s->score;
                if(s->score>gao)
                {
                        gao=s->score;
                }
                if(s->score<di)
                {
                        di=s->score;
                }
                if(s->score>=60)
                {
                        jige++;
                }
        }
        jun/=len;
        float lv=(float)jige/len*100;

        printf("学生总数：%d\n",len);
        printf("最高分：%.1f\n",gao);
        printf("最低分：%.1f\n",di);
        printf("平均分：%.1f\n",jun);
        printf("及格人数：%d\n",jige);
        printf("及格率：%.1f%%\n",lv);
}

void xianshi()
{
        if(len==0)
        {
                printf("没人显示啥？");
                return;
        }

        printf("%-12s %-10s %-8s\n","学号","姓名","成绩");
        for(int i=0;i<len;i++)
        {
                student*s=&stu[i];
                printf("%-12s %-10s %-8.1f\n",s->id,s->name,s->score);
        }
        printf("本次共显示%d名学生\n",len);
}

int baocun()
{
        FILE*fp=fopen(DATA_FILE,"w");
        if(fp==NULL)
        {
                printf("文件保存失败！无法打开%s！\n",DATA_FILE);
                return -1;
        }

        fprintf(fp,"%d\n",len);
        for(int j=0;j<len;j++)
        {
                student*s=&stu[j];
                fprintf(fp,"%s,%s,%.1f\n",s->id,s->name,s->score);
        }
        fclose(fp);
        return 0;
}

int duqu()
{
        FILE*fp=fopen(DATA_FILE,"r");
        if(fp==NULL)
        {
                return -1;
        }

        if(fscanf(fp,"%d\n",&len)!=1)
        {
                printf("文件错误！无法读取！\n");
                fclose(fp);
                return -1;
        }

        for(int i=0;i<len;i++)
        {
                student*s=&stu[i];
                if(fscanf(fp,"%[^,],%[^,],%f\n",s->id,s->name,&s->score)!=3)
                {
                        printf("文件格式错误！第%d个学生数据读取失败。\n", i + 1);
                        fclose(fp);
                        return -1;
                }
        }
        fclose(fp);
        return 0;
}

void chushihua()
{
        students=(student*)malloc(maxlen*sizeof(student));
        if(students==NULL)
        {
                printf("系统初始化失败！内存分配错误。\n");
                exit(1);
        }

        if(duqu()==0)
        {
                printf("系统初始化成功！已加载历史数据（共 %d 名学生）\n", len);
        }
        else
        {
                printf("系统初始化成功！无历史数据（首次使用）\n");
        }
}



int main()
{
        int xuanze;
        chushihua();

        while(1)
        {
                printf("0. 退出学生系统  1. 录入学生信息  2. 查询学生信息\n");
                printf("3. 排序学生信息  4. 统计成绩信息  5. 显示所有学生\n");
                printf("请输入操作编号：");
                scanf("%d",&xuanze);
                switch(xuanze)
                {
                        case 1:luru();baocun();break;
                        case 2:chaxun();baocun();break;
                        case 3:paixu();baocun();break;
                        case 4:tongji();break;
                        case 5:xianshi();break;
                        case 0:baocun();
                               printf("已保存并退出！");
                                       return 0;
                        default:printf("请输入正确编号！");
                }
        }
}
