#include<stdio.h>
#include<stdlib.h>
#define len sizeof(struct dadt)

struct dadt{
	int num;
	struct dadt *next;
};                           //����һ������Ľṹ 

int main(){
	struct dadt *p=NULL,*head=NULL,*temp=NULL,*x=NULL,*fast=NULL,*slow=NULL;
	int n;
	int a=0;
	printf("������һ����������");
	scanf("%d",&n);
	if(n<=0){
		printf("������һ��������");
		return 1;
	}
	for(int i=0;i<n;i++){
		p=(struct dadt *)malloc(len);
		if(p==NULL){
			printf("�����ڴ�ʧ��");
			while(head!=NULL){
				temp=head;
				head=head->next;
				free(temp);                      //�����ͷ��ڴ� 
			}
			return 1;
		}
		printf("������һ��������");
		scanf("%d",&p->num);                    //Ϊ�⹹��ֵ 
		p->next=NULL;
		if(i==0){
			head=p;
		}
		else{
			x->next=p;
		}
		x=p;                                    //���ڵ������� 
	}
	p->next=head;                              //ͨ�����������������������ѭ����� 
	if(n==1){                                   //����ǵ��ڵ㣬��ô����Ϊ��ѭ�� 
		printf("��ѭ��");
		return 0;
	}
	fast=head;
	slow=head;                               //���������������ƶ��ģ��ٶ��п���������ָ�� 
	while(fast!=NULL&&fast->next!=NULL){          
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow){
			a=1;
			break;                           //ͨ��������ָ���Ƿ��������ж��Ƿ�ѭ�� 
		}}
	if(a==1){
		printf("ѭ��");	
	}
	else{
		printf("��ѭ��");
	}
	while(head!=NULL){
			temp=head;
			head=head->next;
			free(temp);}                      //�ͷŷ�����ڴ� 
	return 0;
}
