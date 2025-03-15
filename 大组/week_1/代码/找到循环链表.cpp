#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct dadt)

struct dadt{
	int num;
	struct dadt *next;
};                           //定义一个单向的结构 

int main(){
	struct dadt *p=NULL,*head=NULL,*temp=NULL,*x=NULL,*fast=NULL,*slow=NULL;
	int n;
	int a=0;
	printf("请输入一个正整数：");
	scanf("%d",&n);
	if(n<=0){
		printf("请输入一个正整数");
		return 1;
	}
	for(int i=0;i<n;i++){
		p=(struct dadt *)malloc(len);
		if(p==NULL){
			printf("分配内存失败");
			while(head!=NULL){
				temp=head;
				head=head->next;
				free(temp);                      //报错并释放内存 
			}
			return 1;
		}
		printf("请输入一个整数：");
		scanf("%d",&p->num);                    //为解构赋值 
		p->next=NULL;
		if(i==0){
			head=p;
		}
		else{
			x->next=p;
		}
		x=p;                                    //将节点连起来 
	}
	p->next=head;                              //通过该语句的有无来控制链表的循环与否 
	if(n==1){                                   //如果是单节点，那么就认为不循环 
		printf("不循环");
		return 0;
	}
	fast=head;
	slow=head;                               //定义两个沿链表移动的，速度有快慢的两个指针 
	while(fast!=NULL&&fast->next!=NULL){          
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow){
			a=1;
			break;                           //通过这两个指针是否相遇来判断是否循环 
		}}
	if(a==1){
		printf("循环");	
	}
	else{
		printf("不循环");
	}
	while(head!=NULL){
			temp=head;
			head=head->next;
			free(temp);}                      //释放分配的内存 
	return 0;
}
