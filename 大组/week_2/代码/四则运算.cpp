#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// �������������
struct node {
    int mu;
    char r;
    struct node *next;
};

// ������������ 
struct num {
    float u;
    struct num *next;
};

// ȫ�ֱ���
struct node *ad = NULL;
struct num *bd = NULL;

// �ж���������ȼ�
int rank(char a) {
    if (a == '*' || a == '/') {
        return 2;
    }
    if (a == '+' || a == '-') {
        return 1;
    }
    return 0;
}

// ִ������
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
                printf("Error: ��������Ϊ0!\n");                //���ǳ���Ϊ0����������ⱨ�� 
                exit(1);
            }
            return a / b;
        default:
            return 0;
    }
}

// �����ջ��ջ
void push_op(char op) {
    struct node *p1 = (struct node *)malloc(sizeof(struct node));
    if (p1 == NULL) {
        printf("�����ڴ�ʧ��!\n");
        exit(1);
    }
    p1->r = op;
    p1->mu = rank(op);
    p1->next = ad;
    ad = p1;
}

// �����ջ��ջ
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

// ����ջ��ջ
void push_num(float num) {
    struct num *p2 = (struct num *)malloc(sizeof(struct num));
    if (p2 == NULL) {
        printf("�����ڴ�ʧ��!\n");
        exit(1);
    }
    p2->u = num;
    p2->next = bd;
    bd = p2;
}

// ����ջ��ջ
float pop_num() {
    if (bd == NULL) {
        printf("Error: ����ջΪ��!\n");
        exit(1);
    }
    struct num *temp = bd;
    float num = temp->u;
    bd = bd->next;
    free(temp);
    return num;
}

// ��ȡ�����ջ��Ԫ��
char top_op() {
    if (ad == NULL) {
        return '\0';
    }
    return ad->r;
}

// ������ʽ��ֵ
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
                num = num * 10 + (str[i] - '0');                   //��Ϊ�������ȡ���֣����Ե���������ʱ��ǰ�ߵ�����Ҫǰ��һλ 
                i++;
            }
            push_num(num);
            i--;                                         //������һλ����Ȼ��©���ַ� 
        } else if (str[i] == '(') {
            push_op(str[i]);                             //����'('����ջ 
        } else if (str[i] == ')') {                      //����')'����ʼ���㣬ֱ������'(' 
            char top = top_op();
            while (top != '(' && top != '\0') {
                if (bd == NULL || bd->next == NULL) {
                    printf("Error: ��Ч�ı��!\n");     //���һ�£���������ջ�Ǳ����ֲ��� 
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
                pop_op(); // ����������
            } else {
                printf("Error: ȱ��������!\n");
                exit(1);
            }
        } else {
            while (ad != NULL && rank(top_op()) >= rank(str[i]) && top_op() != '(') {
                if (bd == NULL || bd->next == NULL) {
                    printf("Error: ��Ч�ı��!\n");
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
    // ����ʣ��������
    while (ad != NULL) {
        if (bd == NULL || bd->next == NULL) {
            printf("Error: ��Ч�ı��!\n");
            exit(1);
        }
        if (top_op() == '(') {
            printf("Error: ȱ��������!\n");
            exit(1);
        }
        float b = pop_num();
        float a = pop_num();
        char op = pop_op();
        float result = su(a, b, op);
        push_num(result);
    }
    if (bd == NULL || bd->next != NULL) {
        printf("Error: ��Ч�ı��!\n");
        exit(1);
    }
    return pop_num();
}

int main() {
    char str[100];
    printf("������һ������������ʽ: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input!\n");
        return 1;
    }
    // ȥ�� fgets ���ܶ�ȡ�Ļ��з�
    str[strcspn(str, "\n")] = 0;

    float result = evaluate(str);
    printf("���ʽ�� %s = %.2f\n", str, result);
    return 0;
}
