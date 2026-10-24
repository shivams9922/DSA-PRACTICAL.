
#include <stdio.h>
#define V 4

int main() {
    int graph[V][V] = {
        {0, 4, 0, 5},
        {2, 0, 9, 8},
        {0, 13, 0, 0},
        {2, 8, 0, 0}
    };

    int visited[V] = {0};
    int edges = 0, min, u = -1, v = -1;
    int total = 0;

    visited[0] = 1;
    printf("Edge | Weight\n");

    while (edges < V - 1) {
        min = 999;
        u = -1;
        v = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && graph[i][j] != 0 &&
                        graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("MST not possible\n");
            return 1;
        }

        printf("%d - %d | %d\n", u, v, min);
        visited[v] = 1;
        total += min;
        edges++;
    }

    printf("\nTotal MST Weight = %d\n", total);

    return 0;
}
