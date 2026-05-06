#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct QueueNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

int vertical[200][200];
int count[200];

struct QueueNode queue[200];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QueueNode dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    int offset = 100;

    enqueue(root, 0);

    while (!isEmpty()) {
        struct QueueNode q = dequeue();

        struct Node* curr = q.node;
        int hd = q.hd;

        vertical[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, hd - 1);

        if (curr->right)
            enqueue(curr->right, hd + 1);
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", vertical[i][j]);
            }
            printf("\n");
        }
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

    verticalOrder(root);

    return 0;
}