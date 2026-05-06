#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* createNode(int value) {

    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

void enqueue(int value) {

    struct Node* newNode = createNode(value);

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

void dequeue() {

    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;

    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

int main() {

    int n, value;
    char operation[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", operation);

        if (strcmp(operation, "enqueue") == 0) {

            scanf("%d", &value);

            enqueue(value);
        }

        else if (strcmp(operation, "dequeue") == 0) {

            dequeue();
        }
    }

    return 0;
}