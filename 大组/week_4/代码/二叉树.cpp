#include <stdio.h>
#include <stdlib.h>

// �����������ڵ㶨��
typedef struct BSTNode {
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// ����
BSTNode* searchBST(BSTNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    else if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

// ����
BSTNode* insertIntoBST(BSTNode* root, int val) {
    if (root == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        newNode->val = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// ɾ��
BSTNode* findMin(BSTNode* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        } else {
            BSTNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    return root;
}

// ����������ݹ飩
void preorderTraversalRecursive(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }
}
// ����������ݹ飩
void inorderTraversalRecursive(BSTNode* root) {
    if (root != NULL) {
        inorderTraversalRecursive(root->left);
        printf("%d ", root->val);
        inorderTraversalRecursive(root->right);
    }
}
// ����������ݹ飩
void postorderTraversalRecursive(BSTNode* root) {
    if (root != NULL) {
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        printf("%d ", root->val);
    }
}

// ����������ǵݹ飩
void preorderTraversalIterative(BSTNode* root) {
    if (root == NULL) return;
    BSTNode* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top != -1) {
        BSTNode* node = stack[top--];
        printf("%d ", node->val);
        if (node->right != NULL) stack[++top] = node->right;
        if (node->left != NULL) stack[++top] = node->left;
    }
}
// ����������ǵݹ飩
void inorderTraversalIterative(BSTNode* root) {
    if (root == NULL) return;
    BSTNode* stack[100];
    int top = -1;
    BSTNode* current = root;
    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->val);
        current = current->right;
    }
}
// ����������ǵݹ飩
void postorderTraversalIterative(BSTNode* root) {
    if (root == NULL) return;
    BSTNode* stack1[100];
    BSTNode* stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 != -1) {
        BSTNode* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left != NULL) stack1[++top1] = node->left;
        if (node->right != NULL) stack1[++top1] = node->right;
    }
    while (top2 != -1) {
        BSTNode* node = stack2[top2--];
        printf("%d ", node->val);
    }
}

// �������
void levelOrderTraversal(BSTNode* root) {
    if (root == NULL) return;
    BSTNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        BSTNode* node = queue[front++];
        printf("%d ", node->val);
        if (node->left != NULL) queue[rear++] = node->left;
        if (node->right != NULL) queue[rear++] = node->right;
    }
}

// �ͷŶ������������ڴ�
void freeBST(BSTNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    BSTNode* root = NULL;
    // ����ڵ�
    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 60);
    root = insertIntoBST(root, 80);

    // ��������
    printf("����������ݹ飩: ");
    preorderTraversalRecursive(root);
    printf("\n");

    printf("����������ݹ飩: ");
    inorderTraversalRecursive(root);
    printf("\n");

    printf("����������ݹ飩: ");
    postorderTraversalRecursive(root);
    printf("\n");

    printf("����������ǵݹ飩: ");
    preorderTraversalIterative(root);
    printf("\n");

    printf("����������ǵݹ飩: ");
    inorderTraversalIterative(root);
    printf("\n");

    printf("����������ǵݹ飩: ");
    postorderTraversalIterative(root);
    printf("\n");

    printf("�������: ");
    levelOrderTraversal(root);
    printf("\n");

    // ɾ���ڵ����
    root = deleteNode(root, 20);
    printf("ɾ���ڵ� 20 ���������: ");
    inorderTraversalRecursive(root);
    printf("\n");

    // ���ҽڵ����
    BSTNode* found = searchBST(root, 40);
    if (found) {
        printf("�ҵ��ڵ� %d\n", found->val);
    } else {
        printf("δ�ҵ��ڵ� 40\n");
    }

    // �ͷ��ڴ�
    freeBST(root);

    return 0;
}
    
