#include <stdio.h>

int adj[100][100];
int visited[100];
int queue[100];

int front = 0, rear = 0;
int n;

void enqueue(int value) {
    queue[rear++] = value;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int start) {

    visited[start] = 1;

    enqueue(start);

    while (!isEmpty()) {

        int current = dequeue();

        printf("%d ", current);

        for (int i = 0; i < n; i++) {

            if (adj[current][i] == 1 && !visited[i]) {

                visited[i] = 1;

                enqueue(i);
            }
        }
    }
}

int main() {

    int edges;

    scanf("%d %d", &n, &edges);

    for (int i = 0; i < n; i++) {

        visited[i] = 0;

        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < edges; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    int start;

    scanf("%d", &start);

    bfs(start);

    return 0;
}