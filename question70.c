#include <stdio.h>

#define INF 999999

struct Edge {
    int u, v, w;
};

int main() {

    int n, m;

    scanf("%d %d", &n, &m);

    struct Edge edges[100];

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    int source;

    scanf("%d", &source);

    int dist[100];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[source] = 0;

    for (int i = 1; i <= n - 1; i++) {

        for (int j = 0; j < m; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    int negativeCycle = 0;

    for (int j = 0; j < m; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INF &&
            dist[u] + w < dist[v]) {

            negativeCycle = 1;
            break;
        }
    }

    if (negativeCycle) {
        printf("NEGATIVE CYCLE\n");
    }
    else {

        for (int i = 0; i < n; i++) {
            printf("%d ", dist[i]);
        }
    }

    return 0;
}