#include <stdio.h>
#include <stdlib.h>

// 定义链表节点结构体
struct adt {
    int num;
    struct adt *next;
};

struct adt* reverse(struct adt* head) {
// 判断链表为是否为空或者只有一个节点 
if (head == NULL || head->next == NULL) {
    return head;
}
// 递归反转后续节点
struct adt* newHead = reverse(head->next);             //为接下来的反转操作定好起点，将head起始化为倒数第二个节点 ，并将newhead定义好 
// 反转当前节点和下一个节点的指向
head->next->next = head;                               //将最后一个节点指向上一个节点 
head->next = NULL;                                     //使上一个节点指向NULL，避免运行时出错 
return newHead;                                        //逐级将newhead返回 
}

int main() {
    int n;
    // 提示用户输入单链表长度，打算实现可自定义长度的单向链表 
    printf("请输入单链表长度：");
    scanf("%d", &n); 
    if (n <= 0) {
        // 输入无效，报错并退出程序
        printf("请输入一个正整数\n");
        return 1;
    }

    struct adt *head = NULL, *p = NULL, *prev = NULL,*next=NULL;

    // 循环创建链表节点 
    for (int i = 0; i < n; i++) {
        p = (struct adt *)malloc(sizeof(struct adt));
        if (p == NULL) {
            // 内存分配失败，报错并退出 
            printf("内存分配失败\n");
            // 释放之前分配的节点内存
            while (head != NULL) {
                struct adt *temp = head;
                head = head->next;
                free(temp);
            }
            return 1;
        }

        // 提示用户输入一个整数，用来作为节点的内容 
        printf("请输入一个整数：");
        scanf("%d", &p->num);
        p->next = NULL;

        if (i == 0) {
            // 第一个节点作为头节点
            head = p;
        } else {
            // 连接当前节点到前一个节点
            prev->next = p;
        }
        prev = p; //这一步是实现连接节点的关键，上一步把原本处于末端的节点尾部指向新节点， 这一步把它又变成了末端节点 
    }

    // 遍历链表并输出每个节点的值
    p = head;
    while (p != NULL) {
        printf("%d", p->num);
        p = p->next;
        printf("\n");    //打算每输出一个数字就换一行，直接放在%d后面没效果 
    }

	
 	head=reverse(head);         //调用反转函数 
	
	printf("反转后的链表为：\n");
	p = head;
    while (p != NULL) {
        printf("%d", p->num);
        p = p->next;
        printf("\n");    //打算每输出一个数字就换一行，直接放在%d后面没效果 
    }
    // 用来释放链表节点的内存的 
    p = head;
    while (p != NULL) {
        struct adt *temp = p;
        p = p->next;
        free(temp);
    }
    

    return 0;
}
