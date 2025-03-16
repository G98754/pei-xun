#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�ṹ��
struct adt {
    int num;
    struct adt *next;
};

int main() {
    int n;
    // ��ʾ�û����뵥�����ȣ�����ʵ�ֿ��Զ��峤�ȵĵ������� 
    printf("�����뵥�����ȣ�");
    scanf("%d", &n); 
    if (n <= 0) {
        // ������Ч�������˳�����
        printf("������һ��������\n");
        return 1;
    }

    struct adt *head = NULL, *p = NULL, *prev = NULL,*next=NULL;

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

        // ��ʾ�û�����һ��������������Ϊ�ڵ������ 
        printf("������һ��������");
        scanf("%d", &p->num);
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

    // �����������ÿ���ڵ��ֵ
    p = head;
    while (p != NULL) {
        printf("%d", p->num);
        p = p->next;
        printf("\n");    //����ÿ���һ�����־ͻ�һ�У�ֱ�ӷ���%d����ûЧ�� 
    }

	
	p=head;prev=NULL;             //ʹ������ָ�룬p���飬prev����ǰһ���ڵ�ĵ�ַ��next�����һ���ڵ�ĵ�ַ 
	while(p!=NULL){
		next=p->next;          
		p->next=prev;            //��pָ��prev,ָ��ת 
		prev=p;                  
		p=next;                  //������prev��p�����ƶ�һ���ڵ㣬���ں������� 
	}
	head=prev;                    //���±�ͷ 
	
	printf("��ת�������Ϊ��\n");
	p = head;
    while (p != NULL) {
        printf("%d", p->num);
        p = p->next;
        printf("\n");    //����ÿ���һ�����־ͻ�һ�У�ֱ�ӷ���%d����ûЧ�� 
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
