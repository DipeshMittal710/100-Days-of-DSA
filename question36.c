#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int value) {

    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

void deleteElement() {

    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void peek() {

    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);
}

int main() {

    int n, value;
    char operation[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        scanf("%s", operation);

        if (strcmp(operation, "insert") == 0) {

            scanf("%d", &value);
            insert(value);
        }

        else if (strcmp(operation, "delete") == 0) {
            deleteElement();
        }

        else if (strcmp(operation, "peek") == 0) {
            peek();
        }
    }

    return 0;
}