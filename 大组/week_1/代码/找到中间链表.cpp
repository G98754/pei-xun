#include <stdio.h>
#include <stdlib.h>
 
// ��������ڵ�ṹ��
struct adt {
    int num;
    struct adt *next;
};

int main() {
    int n=11;   //���ڴ���һ������Ϊ11�ĵ����� 
    int j=0;

    
    struct adt *head = NULL, *p = NULL, *prev = NULL;

    // ѭ����������ڵ� 
    for (int i = 0; i < n; i++) {
        p = (struct adt *)malloc(sizeof(struct adt));
        if (p == NULL) {
            // �ڴ����ʧ�ܣ������˳� 
            printf("�ڴ����ʧ��\n");
            // �ͷ�֮ǰ����Ľڵ��ڴ�
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
            // ��һ���ڵ���Ϊͷ�ڵ�
            head = p;
        } else {
            // ���ӵ�ǰ�ڵ㵽ǰһ���ڵ�
            prev->next = p;
        }
        prev = p; //��һ����ʵ�����ӽڵ�Ĺؼ�����һ����ԭ������ĩ�˵Ľڵ�β��ָ���½ڵ㣬 ��һ�������ֱ����ĩ�˽ڵ� 
    }
    //���γɵĵ������ǵ���� 

    // ��������
    p = head;
    while (p != NULL) {
        j++;              //����ÿ����һ���ڵ�ͼ�һ�������жϽڵ��ܳ���
		p=p->next;     
    }
    p = head;
    if(j%2==0){
    	printf("��Ϊ������ż�������ȣ������м����������� ");
    	for(int i=0;i<j;i++){         //����ÿ����һ���ڵ�ͼ�һ�������жϵ�ǰ�ڵ㳤��
		if(i==j/2-1){
			printf("�м�����ĵ�ַΪ��%p ",(void *)p);       
		}
		if(i==j/2){
			printf("�м�����ĵ�ַΪ��%p ",(void *)p);           //��Ϊ��ż�������ȣ������м����������� 
			break;
		}
		p=p->next;     	
		}
	}
	    if(j%2!=0){
    	printf("��Ϊ���������������ȣ������м�������һ�� ");
    	for(int i=0;i<j;i++){   //����ÿ����һ���ڵ�ͼ�һ�������жϵ�ǰ�ڵ㳤��
		if(i==j/2){
			printf("�м�����ĵ�ַΪ��%p ",(void *)p);           //��Ϊ���������������ȣ������м�������һ��
			break;
		}
		p=p->next;     	
		}
	}
    // �����ͷ�����ڵ���ڴ�� 
    p = head;
    while (p != NULL) {
        struct adt *temp = p;
        p = p->next;
        free(temp);
    }

    return 0;
}
