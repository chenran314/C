#include <stdio.h>

int main() {
    char a;
    int i;

    printf("请输入一个字符：");
    scanf("%c", &a);

    for (i = 7; i >= 0; i--) {

        int bit = (a >> i) & 1;//其实我不知道这个代码的意思，查AI会的，差不多就是判断ASCII>的每一位是0还是1

        switch (i + 1) {
            case 8: printf("The eighth bit is %d,\n", bit); break;
            case 7: printf("The seventh bit is %d,\n", bit); break;
            case 6: printf("The sixth bit is %d,\n", bit); break;
            case 5: printf("The fifth bit is %d,\n", bit); break;
            case 4: printf("The fourth bit is %d,\n", bit); break;
            case 3: printf("The third bit is %d,\n", bit); break;
            case 2: printf("The second bit is %d,\n", bit); break;
            case 1: printf("The first bit is %d.\n", bit); break;
        }
    }

    return 0;
}
