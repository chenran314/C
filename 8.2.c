#include<stdio.h>
#include<stdlib.h>
#include<time.h>//使用到了time，srand的函数，帮助生成随机食物
#include<unistd.h>//使用到了tcgetattr，read的函数，帮助读取键盘输入
#include<termios.h>//使用到了下文static中的函数，帮助按wasd时即时回应，不干扰画面
#include<fcntl.h>//使用到了F_SETEL等函数，帮助不按键盘时蛇不停下
#include<errno.h>//使用到了errno，EINTR等量，确保mysleep(200)准确休眠200ms

#define W 30
#define H 20

typedef enum{UP,DOWN,LEFT,RIGHT}Dir;//枚举类型，定义了一组有名字1的整数常量，此处u=0，d=1，l=2，r=3

typedef struct Node//创建链表形式的蛇节点
{
        int x,y;
        struct Node*next;
}
Node;

Node*head=NULL;//蛇头
Dir dir=RIGHT;//初始方向
int fx,fy;//食物坐标
int over=0;//结束标志

void init();//初始化程序
void draw();//画图
void ctrl();//键盘控制
void move();//蛇移动
int collide();//检测碰撞
void freeSnake();//游戏结束释放内存

static struct termios old,new;
void initTermios()
{
        tcgetattr(STDIN_FILENO,&old);//读取配置到old里
        new=old;
        new.c_lflag &= ~(ICANON | ECHO);//关闭规范模式和回显
        tcsetattr(STDIN_FILENO, TCSANOW, &new);//应用新配置
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);//设置输入为非阻塞模式
}
void resetTermios() { tcsetattr(STDIN_FILENO, TCSANOW, &old); }//恢复原配置

void mySleep(unsigned long ms)
{
        struct timespec req, rem;//定义休眠时间结构体，req为请求的时间，rem为剩余未休眠时间
        req.tv_sec = ms / 1000;//休眠的秒数
        req.tv_nsec = (ms % 1000) * 1000000;//剩余休眠的纳秒数
        while (nanosleep(&req, &rem) == -1 && errno == EINTR)
        {//处理休眠中断的情况，若成功休眠指定时间，nanosleep返回0，否则返回-1
                req = rem;
        }
}

int main()
{
        initTermios();//初始化终端
        atexit(resetTermios);//退出并恢复终端设置
        init();

        while(over==0)
        {
                ctrl();
                move();
                over=collide();
                draw();
                mySleep(200);
        }

        printf("\n\n游戏结束！！\n");
        freeSnake();
        return 0;
}



void init() {
        srand(time(NULL));

        head = malloc(sizeof(Node));//创建蛇头
        head->x = W/2; head->y = H/2; head->next = NULL;

        Node *b1 = malloc(sizeof(Node));//创建第一节蛇尾
        b1->x = W/2 -1; b1->y = H/2; b1->next = NULL;
        head->next = b1;

        Node *b2 = malloc(sizeof(Node));//第二节蛇尾
        b2->x = W/2 -2; b2->y = H/2; b2->next = NULL;
        b1->next = b2;

        int ok;//生成初始食物
        do
        {
                fx = rand()%W;
                fy = rand()%H;
                ok = 1;
                Node *t = head;
                while (t)
                {
                         if (t->x == fx && t->y == fy)
                         {
                                 ok = 0;
                                 break;
                         }
                 t = t->next;
                }
        } while (!ok);
}

void draw() {
    system("clear");

    for (int i=0; i<=W+1; i++) printf("■");//上边界
    printf("\n");

    for (int y=0; y<H; y++) {
        printf("■"); //左边界
        for (int x=0; x<W; x++) {
            if (x == head->x && y == head->y) { printf("●"); continue; }//蛇头
            Node *t = head->next;
            int isBody = 0;
            while (t) {
                if (t->x == x && t->y == y) { printf("○"); isBody=1; break; }//蛇身
                t = t->next;
            }
            if (isBody) continue;
            if (x == fx && y == fy) printf("★");//食物
            else printf(" ");
        }
        printf("■\n");
    }

    for (int i=0; i<=W+1; i++) printf("■");//下边界
    printf("\nW上 A左 S下 D右 | 按Q退出");
}

void ctrl() {
    char c;
    if (read(STDIN_FILENO, &c, 1) == 1) { // 读取键盘输入
        switch(c) {
            case 'w': case 'W': if (dir != DOWN) dir = UP; break;
            case 's': case 'S': if (dir != UP) dir = DOWN; break;
            case 'a': case 'A': if (dir != RIGHT) dir = LEFT; break;
            case 'd': case 'D': if (dir != LEFT) dir = RIGHT; break;
            case 'q': case 'Q': over = 1; break;
        }
    }
}

void move() {
    Node *newHead = malloc(sizeof(Node));//新蛇头移动
    newHead->next = head;
    switch(dir) {
        case UP: newHead->x=head->x; newHead->y=head->y-1; break;
        case DOWN: newHead->x=head->x; newHead->y=head->y+1; break;
        case LEFT: newHead->x=head->x-1; newHead->y=head->y; break;
        case RIGHT: newHead->x=head->x+1; newHead->y=head->y; break;
    }
    head = newHead;

    if (newHead->x == fx && newHead->y == fy) {//吃到食物在原地生成一个蛇身，否则删除蛇尾
        int ok;
        do {
            fx = rand()%W;
            fy = rand()%H;
            ok = 1;//检查食物是否在蛇头上
            Node *t = head;
            while (t) {
                if (t->x == fx && t->y == fy) {
                    ok = 0;
                    break;
                }
                t = t->next;
            }
        } while (!ok);
    } else {
        Node *t = head;
        while (t->next->next) t = t->next; // 找到倒数第二个节点
        free(t->next); t->next = NULL;
    }
}

int collide() {
    // 撞墙
    if (head->x <0 || head->x >=W || head->y <0 || head->y >=H) return 1;
    // 撞自身
    Node *t = head->next;
    while (t) {
        if (t->x == head->x && t->y == head->y) return 1;
        t = t->next;
    }
    return 0;
}

void freeSnake() {
    Node *t;
    while (head) { t=head; head=head->next; free(t); }
}
