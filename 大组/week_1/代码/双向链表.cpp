#include <stdio.h>
#include <stdlib.h>

#define len sizeof(struct ddat)

struct ddat {
    int num;
    struct ddat *pre;
    struct ddat *next;
};

// 清理输入缓冲区的函数
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}						//没有这个的话，代码无法正常运行，会直接认为输入值<0 


int main() {
    struct ddat *head1 = NULL, *head2 = NULL, *p1 = NULL, *p2 = NULL, *temp1 = NULL, *temp2 = NULL;
    int n;

    printf("请输入一个正整数：");
    scanf("%d", &n);

    if (n < 0) {
        printf("请输入一个正整数");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        p1 = (struct ddat *)malloc(len);
        p2 = (struct ddat *)malloc(len);        //以p1、p2为两个起始点 

        if (p1 == NULL || p2 == NULL) {
            printf("分配内存失败");
            // 释放已分配的节点内存
            while (head1 != NULL) {
                temp1 = head1;
                head1 = head1->next;
                free(temp1);
            }
            while (head2 != NULL) {
                temp2 = head2;
                head2 = head2->next;
                free(temp2);
            }
            return 1;
        }

        printf("前：请输入一个整数：");
        scanf("%d", &p1->num);
        printf("后：请输入一个整数：");
        scanf("%d", &p2->num);
        p2->next=NULL;
        p1->pre=NULL;
        p1->next=NULL;
        p2->pre=NULL;

        if (i == 0) {
            head1 = p1;
            head2 = p2;
        } else {
            temp1->pre=p1;
            p1->next=temp1;
            temp2->next=p2;
            p2->pre=temp2;      //分别从p1向前、从p2向后连接 
        }

        temp1 = p1;
        temp2 = p2;
    }

	head1->next=head2;
	head2->pre=head1;
	p1=head1;p2=head2;      //将p1和p2连接起来 

    // 遍历链表并输出数据
	while(p1!=NULL||p2!=NULL){
		printf("%d      %d",p1->num,p2->num);
		p1=p1->pre;
		p2=p2->next;
	}
	
	
	while(p1!=NULL||p2!=NULL){
		temp1=p1;temp2=p2;
		p1=p1->pre;
		p2=p2->next;
		free(temp1);
		free(temp2);
	}
    return 0;
}
