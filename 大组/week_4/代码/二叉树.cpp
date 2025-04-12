#include <stdio.h>
#include <stdlib.h>

// 二叉排序树节点定义
typedef struct BSTNode {
    int val;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

// 查找
BSTNode* searchBST(BSTNode* root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    else if (val < root->val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
}

// 插入
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

// 删除
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

// 先序遍历（递归）
void preorderTraversalRecursive(BSTNode* root) {
    if (root != NULL) {
        printf("%d ", root->val);
        preorderTraversalRecursive(root->left);
        preorderTraversalRecursive(root->right);
    }
}
// 中序遍历（递归）
void inorderTraversalRecursive(BSTNode* root) {
    if (root != NULL) {
        inorderTraversalRecursive(root->left);
        printf("%d ", root->val);
        inorderTraversalRecursive(root->right);
    }
}
// 后序遍历（递归）
void postorderTraversalRecursive(BSTNode* root) {
    if (root != NULL) {
        postorderTraversalRecursive(root->left);
        postorderTraversalRecursive(root->right);
        printf("%d ", root->val);
    }
}

// 先序遍历（非递归）
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
// 中序遍历（非递归）
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
// 后序遍历（非递归）
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

// 层序遍历
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

// 释放二叉排序树的内存
void freeBST(BSTNode* root) {
    if (root != NULL) {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

int main() {
    BSTNode* root = NULL;
    // 插入节点
    root = insertIntoBST(root, 50);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 60);
    root = insertIntoBST(root, 80);

    // 遍历测试
    printf("先序遍历（递归）: ");
    preorderTraversalRecursive(root);
    printf("\n");

    printf("中序遍历（递归）: ");
    inorderTraversalRecursive(root);
    printf("\n");

    printf("后序遍历（递归）: ");
    postorderTraversalRecursive(root);
    printf("\n");

    printf("先序遍历（非递归）: ");
    preorderTraversalIterative(root);
    printf("\n");

    printf("中序遍历（非递归）: ");
    inorderTraversalIterative(root);
    printf("\n");

    printf("后序遍历（非递归）: ");
    postorderTraversalIterative(root);
    printf("\n");

    printf("层序遍历: ");
    levelOrderTraversal(root);
    printf("\n");

    // 删除节点测试
    root = deleteNode(root, 20);
    printf("删除节点 20 后中序遍历: ");
    inorderTraversalRecursive(root);
    printf("\n");

    // 查找节点测试
    BSTNode* found = searchBST(root, 40);
    if (found) {
        printf("找到节点 %d\n", found->val);
    } else {
        printf("未找到节点 40\n");
    }

    // 释放内存
    freeBST(root);

    return 0;
}
    
