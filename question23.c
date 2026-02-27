#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, m, x;
    struct Node *l1 = NULL, *l2 = NULL, *t1 = NULL, *t2 = NULL, *newNode;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(l1 == NULL) l1 = t1 = newNode;
        else { t1->next = newNode; t1 = newNode; }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = x;
        newNode->next = NULL;

        if(l2 == NULL) l2 = t2 = newNode;
        else { t2->next = newNode; t2 = newNode; }
    }

    struct Node dummy, *tail = &dummy;
    dummy.next = NULL;

    while(l1 && l2) {
        if(l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;

    struct Node* temp = dummy.next;
    while(temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}