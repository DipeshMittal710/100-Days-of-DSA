#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

int stack[MAX];
int top = -1;

void enqueue(int value) {
    rear++;
    queue[rear] = value;
}

int dequeue() {

    int value = queue[front];

    front++;

    return value;
}

void push(int value) {

    top++;

    stack[top] = value;
}

int pop() {

    int value = stack[top];

    top--;

    return value;
}

int main() {

    int n, value;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%d", &value);

        enqueue(value);
    }

    while (front <= rear) {

        push(dequeue());
    }

    front = 0;
    rear = -1;

    while (top != -1) {

        enqueue(pop());
    }

    for (int i = front; i <= rear; i++) {

        printf("%d ", queue[i]);
    }

    return 0;
}