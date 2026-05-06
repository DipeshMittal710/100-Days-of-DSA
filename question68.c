#include <stdio.h>

int adj[100][100];
int indegree[100];
int queue[100];

int front = 0, rear = 0;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {

    int n, edges;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {

        indegree[i] = 0;

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0; i < n; i++) {

        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    while (!isEmpty()) {

        int current = dequeue();

        printf("%d ", current);

        for (int i = 0; i < n; i++) {

            if (adj[current][i]) {

                indegree[i]--;

                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    return 0;
}