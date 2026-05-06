#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int postIndex;

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[],
                       int start, int end) {

    if (start > end)
        return NULL;

    int current = postorder[postIndex--];

    struct Node* root = createNode(current);

    if (start == end)
        return root;

    int inIndex = search(inorder, start, end, current);

    root->right = buildTree(inorder, postorder,
                            inIndex + 1, end);

    root->left = buildTree(inorder, postorder,
                           start, inIndex - 1);

    return root;
}

void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    postIndex = n - 1;

    struct Node* root =
        buildTree(inorder, postorder, 0, n - 1);

    preorder(root);

    return 0;
}