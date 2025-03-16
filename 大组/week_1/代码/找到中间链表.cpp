#include <stdio.h>
#include <stdlib.h>
 
// 定义链表节点结构体
struct adt {
    int num;
    struct adt *next;
};

int main() {
    int n=11;   //用于创建一个长度为11的单链表 
    int j=0;

    
    struct adt *head = NULL, *p = NULL, *prev = NULL;

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


        p->num=i;
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
    //所形成的单链表是单向的 

    // 遍历链表
    p = head;
    while (p != NULL) {
        j++;              //打算每经历一个节点就加一，用于判断节点总长度
		p=p->next;     
    }
    p = head;
    if(j%2==0){
    	printf("因为链表有偶数个长度，所以中间链表有两个 ");
    	for(int i=0;i<j;i++){         //打算每经历一个节点就加一，用于判断当前节点长度
		if(i==j/2-1){
			printf("中间链表的地址为：%p ",(void *)p);       
		}
		if(i==j/2){
			printf("中间链表的地址为：%p ",(void *)p);           //因为有偶数个长度，所以中间链表有两个 
			break;
		}
		p=p->next;     	
		}
	}
	    if(j%2!=0){
    	printf("因为链表有奇数个长度，所以中间链表有一个 ");
    	for(int i=0;i<j;i++){   //打算每经历一个节点就加一，用于判断当前节点长度
		if(i==j/2){
			printf("中间链表的地址为：%p ",(void *)p);           //因为链表有奇数个长度，所以中间链表有一个
			break;
		}
		p=p->next;     	
		}
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
