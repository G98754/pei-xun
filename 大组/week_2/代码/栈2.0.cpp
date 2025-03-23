#include <stdio.h>
#include <stdlib.h>
#define len sizeof(struct node)

// 定义队列节点结构体
struct node {
    int num;
    struct node *next;
};

// 队首指针
struct node *p = NULL;
// 队尾指针
struct node *rear = NULL;            //用两个指针来操作会比较方便 

// 元素入队
void push(int a) {
    struct node *newNode = (struct node *)malloc(len);
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    newNode->num = a;
    newNode->next = NULL;
    if (p == NULL) {
        p = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}                               //其实就是按照上次作业单链表 

// 打印队列
void print() {
    struct node *temp = p;
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

// 检测队列长度
void lens() {
    struct node *temp = p;
    int t = 0;
    while (temp != NULL) {
        t++;
        temp = temp->next;
    }
    printf("队列长度为: %d\n", t);
}

// 销毁队列
void dele() {
    struct node *temp = p;
    while (temp != NULL) {
        struct node *q = temp;
        temp = temp->next;
        free(q);
    }
    p = rear = NULL;
}

// 元素出队 
void pull() {
    if (p == NULL) {
        printf("队伍中没有元素\n");
        return;
    }
    struct node *temp = p;
    p = p->next;
    if (p == NULL) {
        rear = NULL;
    }
    free(temp);
}

// 判断队列是否为空
void empty() {
    if (p == NULL) {
        printf("队伍为空\n");
    } else {
        printf("队伍不为空\n");
    }
}

// 取队首元素
void first() {
    if (p == NULL) {
        printf("队伍中没有元素\n");
        return;
    }
    printf("队首元素为: %d\n", p->num);
}

// 重新初始化队列，反正原有队列不用了，干脆销毁掉 
void init() {
    dele();
}

int main() {
    int n, m;
    while (1) {
        printf("1.元素入队\n");
        printf("2.元素出队\n");
        printf("3.判断队伍是否为空\n");
        printf("4.取队首元素\n");
        printf("5.销毁队\n");
        printf("6.检测队伍的长度\n");
        printf("7.重新初始化队伍\n");
        printf("8.打印队\n");
        printf("9.退出程序\n");
        printf("请输入指令: ");                             //做个用户交互界面 
        if (scanf("%d", &n) != 1) {
            printf("请输入数字\n");
            while (getchar() != '\n');
            continue;
        }
        switch (n) {
            case 1:
                printf("请输入要入队的元素: ");
                if (scanf("%d", &m) != 1) {
                    printf("请输入数字\n");
                    while (getchar() != '\n');
                    break;
                }
                push(m);
                printf("\n\n");                            //多加几行，为了视觉上的舒适，不然容易找不到输出结果 
                break;
            case 2:
                pull();
                printf("\n\n"); 
                break;
            case 3:
                empty();
                printf("\n\n"); 
                break;
            case 4:
                first();
                printf("\n\n"); 
                break;
            case 5:
                dele();
                printf("\n\n"); 
                break;
            case 6:
                lens();
                printf("\n\n"); 
                break;
            case 7:
                init();
                printf("\n\n"); 
                break;
            case 8:
                print();
                printf("\n\n"); 
                break;
            case 9:
                dele();
                printf("\n\n"); 
                return 0;
            default:
                printf("请输入有效数字\n");
                printf("\n\n"); 
        }
    }
    return 0;
}    
