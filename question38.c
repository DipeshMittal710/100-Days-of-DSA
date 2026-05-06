#include <stdio.h>
#include <string.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

int empty() {
    return (front == -1);
}

int size() {

    if (empty())
        return 0;

    return rear - front + 1;
}

void push_front(int value) {

    if (front == 0) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    }
    else {
        front--;
    }

    deque[front] = value;
}

void push_back(int value) {

    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }

    if (empty()) {
        front = rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
}

void pop_front() {

    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void pop_back() {

    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear--;
    }
}

void getFront() {

    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);
}

void getBack() {

    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);
}

void clearDeque() {
    front = rear = -1;
}

void display() {

    if (empty()) {
        printf("Deque is Empty\n");
        return;
    }

    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }

    printf("\n");
}

int main() {

    int n, value;
    char operation[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", operation);

        if (strcmp(operation, "push_front") == 0) {

            scanf("%d", &value);
            push_front(value);
        }

        else if (strcmp(operation, "push_back") == 0) {

            scanf("%d", &value);
            push_back(value);
        }

        else if (strcmp(operation, "pop_front") == 0) {
            pop_front();
        }

        else if (strcmp(operation, "pop_back") == 0) {
            pop_back();
        }

        else if (strcmp(operation, "front") == 0) {
            getFront();
        }

        else if (strcmp(operation, "back") == 0) {
            getBack();
        }

        else if (strcmp(operation, "size") == 0) {
            printf("%d\n", size());
        }

        else if (strcmp(operation, "empty") == 0) {
            printf("%d\n", empty());
        }

        else if (strcmp(operation, "clear") == 0) {
            clearDeque();
        }

        else if (strcmp(operation, "display") == 0) {
            display();
        }
    }

    return 0;
}