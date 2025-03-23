#include <stdio.h>
#include <stdlib.h>
#define len sizeof(struct node)

// ������нڵ�ṹ��
struct node {
    int num;
    struct node *next;
};

// ����ָ��
struct node *p = NULL;
// ��βָ��
struct node *rear = NULL;            //������ָ����������ȽϷ��� 

// Ԫ�����
void push(int a) {
    struct node *newNode = (struct node *)malloc(len);
    if (newNode == NULL) {
        printf("�ڴ����ʧ�ܣ�\n");
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
}                               //��ʵ���ǰ����ϴ���ҵ������ 

// ��ӡ����
void print() {
    struct node *temp = p;
    while (temp != NULL) {
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

// �����г���
void lens() {
    struct node *temp = p;
    int t = 0;
    while (temp != NULL) {
        t++;
        temp = temp->next;
    }
    printf("���г���Ϊ: %d\n", t);
}

// ���ٶ���
void dele() {
    struct node *temp = p;
    while (temp != NULL) {
        struct node *q = temp;
        temp = temp->next;
        free(q);
    }
    p = rear = NULL;
}

// Ԫ�س��� 
void pull() {
    if (p == NULL) {
        printf("������û��Ԫ��\n");
        return;
    }
    struct node *temp = p;
    p = p->next;
    if (p == NULL) {
        rear = NULL;
    }
    free(temp);
}

// �ж϶����Ƿ�Ϊ��
void empty() {
    if (p == NULL) {
        printf("����Ϊ��\n");
    } else {
        printf("���鲻Ϊ��\n");
    }
}

// ȡ����Ԫ��
void first() {
    if (p == NULL) {
        printf("������û��Ԫ��\n");
        return;
    }
    printf("����Ԫ��Ϊ: %d\n", p->num);
}

// ���³�ʼ�����У�����ԭ�ж��в����ˣ��ɴ����ٵ� 
void init() {
    dele();
}

int main() {
    int n, m;
    while (1) {
        printf("1.Ԫ�����\n");
        printf("2.Ԫ�س���\n");
        printf("3.�ж϶����Ƿ�Ϊ��\n");
        printf("4.ȡ����Ԫ��\n");
        printf("5.���ٶ�\n");
        printf("6.������ĳ���\n");
        printf("7.���³�ʼ������\n");
        printf("8.��ӡ��\n");
        printf("9.�˳�����\n");
        printf("������ָ��: ");                             //�����û��������� 
        if (scanf("%d", &n) != 1) {
            printf("����������\n");
            while (getchar() != '\n');
            continue;
        }
        switch (n) {
            case 1:
                printf("������Ҫ��ӵ�Ԫ��: ");
                if (scanf("%d", &m) != 1) {
                    printf("����������\n");
                    while (getchar() != '\n');
                    break;
                }
                push(m);
                printf("\n\n");                            //��Ӽ��У�Ϊ���Ӿ��ϵ����ʣ���Ȼ�����Ҳ��������� 
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
                printf("��������Ч����\n");
                printf("\n\n"); 
        }
    }
    return 0;
}    
