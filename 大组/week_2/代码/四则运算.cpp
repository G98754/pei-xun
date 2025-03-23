#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 定义运算符链表
struct node {
    int mu;
    char r;
    struct node *next;
};

// 定义数字链表 
struct num {
    float u;
    struct num *next;
};

// 全局变量
struct node *ad = NULL;
struct num *bd = NULL;

// 判断运算符优先级
int rank(char a) {
    if (a == '*' || a == '/') {
        return 2;
    }
    if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

// 执行运算
float su(float a, float b, char c) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("Error: 除数不能为0!\n");                //考虑除数为0的情况，避免报错 
                exit(1);
            }
            return a / b;
        default:
            return 0;
    }
}

// 运算符栈入栈
void push_op(char op) {
    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    if (p1 == NULL) {
        printf("分配内存失败!\n");
        exit(1);
    }
    p1->r = op;
    p1->mu = rank(op);
    p1->next = ad;
    ad = p1;
}

// 运算符栈出栈
char pop_op() {
    if (ad == NULL) {
        return '\0';
    }
    struct node *temp = ad;
    char op = temp->r;
    ad = ad->next;
    free(temp);
    return op;
}

// 数字栈入栈
void push_num(float num) {
    struct num *p2 = (struct num *)malloc(sizeof(struct num));
    if (p2 == NULL) {
        printf("分配内存失败!\n");
        exit(1);
    }
    p2->u = num;
    p2->next = bd;
    bd = p2;
}

// 数字栈出栈
float pop_num() {
    if (bd == NULL) {
        printf("Error: 数字栈为空!\n");
        exit(1);
    }
    struct num *temp = bd;
    float num = temp->u;
    bd = bd->next;
    free(temp);
    return num;
}

// 获取运算符栈顶元素
char top_op() {
    if (ad == NULL) {
        return '\0';
    }
    return ad->r;
}

// 计算表达式的值
float evaluate(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            i++;
            continue;
        }
        if (isdigit(str[i])) {
            float num = 0;
            while (isdigit(str[i])) {
                num = num * 10 + (str[i] - '0');                   //因为是逐个读取数字，所以当数字连续时，前边的数字要前移一位 
                i++;
            }
            push_num(num);
            i--;                                         //往回退一位，不然会漏掉字符 
        } else if (str[i] == '(') {
            push_op(str[i]);                             //发现'('，入栈 
        } else if (str[i] == ')') {                      //发现')'，开始运算，直到遇到'(' 
            char top = top_op();
            while (top != '(' && top != '\0') {
                if (bd == NULL || bd->next == NULL) {
                    printf("Error: 无效的表达!\n");     //检查一下，避免数字栈那边数字不够 
                    exit(1);
                }
                float b = pop_num();
                float a = pop_num();
                char op = pop_op();
                float result = su(a, b, op);
                push_num(result);
                top = top_op();
            }
            if (top == '(') {
                pop_op(); // 弹出左括号
            } else {
                printf("Error: 缺少左括号!\n");
                exit(1);
            }
        } else {
            while (ad != NULL && rank(top_op()) >= rank(str[i]) && top_op() != '(') {
                if (bd == NULL || bd->next == NULL) {
                    printf("Error: 无效的表达!\n");
                    exit(1);
                }
                float b = pop_num();
                float a = pop_num();
                char op = pop_op();                                    
                float result = su(a, b, op);
                push_num(result);
            }
            push_op(str[i]);
        }
        i++;
    }
    // 处理剩余的运算符
    while (ad != NULL) {
        if (bd == NULL || bd->next == NULL) {
            printf("Error: 无效的表达!\n");
            exit(1);
        }
        if (top_op() == '(') {
            printf("Error: 缺少左括号!\n");
            exit(1);
        }
        float b = pop_num();
        float a = pop_num();
        char op = pop_op();
        float result = su(a, b, op);
        push_num(result);
    }
    if (bd == NULL || bd->next != NULL) {
        printf("Error: 无效的表达!\n");
        exit(1);
    }
    return pop_num();
}

int main() {
    char str[100];
    printf("请输入一个四则运算表达式: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    // 去除 fgets 可能读取的换行符
    str[strcspn(str, "\n")] = 0;

    float result = evaluate(str);
    printf("表达式： %s = %.2f\n", str, result);
    return 0;
}
