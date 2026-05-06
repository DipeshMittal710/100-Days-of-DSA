#include <stdio.h>

#define INF 999999

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    int graph[100][100];

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {

        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        u--;
        v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[100] = {0};
    int minEdge[100];

    for (int i = 0; i < n; i++) {
        minEdge[i] = INF;
    }

    minEdge[0] = 0;

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {

        int min = INF;
        int u = -1;

        for (int i = 0; i < n; i++) {

            if (!selected[i] && minEdge[i] < min) {
                min = minEdge[i];
                u = i;
            }
        }

        selected[u] = 1;

        totalWeight += minEdge[u];

        for (int v = 0; v < n; v++) {

            if (graph[u][v] != INF &&
                !selected[v] &&
                graph[u][v] < minEdge[v]) {

                minEdge[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}