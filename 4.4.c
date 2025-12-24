#include<stdio.h>

int my_strlen(char *str)
{
        int length=0,i=0;
        for(i=0;str[i]!='\0';i++)
        {
                length++;
        }
        return length;
}


int main()
{
        char str[100];
        printf("请输入文本：");
        scanf("%s",str);
        printf("字符串长度为：%d\n",my_strlen(str));
        return 0;
}
