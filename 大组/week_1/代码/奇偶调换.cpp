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

    struct adt *head = NULL, *p = NULL, *prev = NULL,*temp=NULL;

    // ѭ����������ڵ� 
    for (int i = 0; i < n; i++) {
        p = (struct adt *)malloc(sizeof(struct adt));
        if (p == NULL) {
            // �ڴ����ʧ�ܣ������˳� 
            printf("�ڴ����ʧ��\n");
            // �ͷ�֮ǰ����Ľڵ��ڴ�
            while (head != NULL) {
            	temp = head;
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
    
        // �������ڽڵ�
        
    if (head != NULL && head->next != NULL) {           //�ж��Ƿ�Ϊ��������ߵ����� 
        struct adt *newHead = head->next;               //������ڶ����ڵ��Ϊͷ�ڵ� 
        prev = NULL;
        p = head;
        while (p != NULL && p->next != NULL) {          //�жϵ�ǰλ���Ƿ�Ϊ��������ߵ����� 
            temp = p->next;
            p->next = temp->next;
            temp->next = p;                              //�������ڽڵ�Ľ��� 
            if (prev != NULL) {
                prev->next = temp;                        //ʹ������Ľڵ���ǰ���Ѿ������õĽڵ����� 
            }
            prev = p;                                     //����һ���������浱ǰ������Ľڵ�ĩ�� 
            p = p->next;
        }
        head = newHead;
    }
    
    printf("�������ڽڵ�������\n");
    p = head;
    while (p != NULL) {
        printf("%d\n", p->num);
        p = p->next;
    }           //�������������� 
        
    // �����ͷ�����ڵ���ڴ�� 
    p = head;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    

    return 0;
}
