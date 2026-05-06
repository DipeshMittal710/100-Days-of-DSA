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

struct Node* queue[200];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void zigzagTraversal(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;

        int level[size];

        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();

            int index;

            if (leftToRight)
                index = i;
            else
                index = size - 1 - i;

            level[index] = curr->data;

            if (curr->left)
                enqueue(curr->left);

            if (curr->right)
                enqueue(curr->right);
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = createNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct Node* root = nodes[0];

    zigzagTraversal(root);

    return 0;
}