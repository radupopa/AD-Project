#include <stdio.h>
#define INF 0x3fffffff
#define V 6

void find_path(int u, int v, int dist[][V], int pred[][V])
{
    if (pred[u][v] == v) {
        printf("%2d", v);
        return 0;
    }
    find_path(u, pred[u][v], dist, pred);
    printf(" ->%2d", v);
}

void print_path(int dist[][V], int pred[][V])
{
    int i,j;
    printf("Enter the source node: ");
    scanf("%d", &i);
    printf("Enter the destination node: ");
    scanf("%d", &j);
    printf("The shortest path between %d and %d is: \n", i, j);
    if (dist[i][j] == INF) {
        printf("%2s\n", "#");
    }
    find_path(i, j, dist, pred);
    printf("\nThe weight of the path is: %d", dist[i][j]);
}

void floyd(int graph[][V])
{
    int dist[V][V];
    int i, j, k;

    int pred[V][V];

    for (i = 0; i < V; i++){
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            pred[i][j] = i;
        }
    }

    for (k = 0; k < V; k++){
        for (i = 0; i < V; i++){
            for (j = 0; j < V; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = k;
                }
            }
        }
    }

    print_path(dist, pred);
}

int main(void)
{
    int graph[V][V] = {
           0,      135,    INF,    87,     157,    INF,
        135,    0,      128,    INF,    INF,    INF,
        INF,    128,    0,      118,    44,     INF,
        87,     INF,    118,    0,      INF,    INF,
        157,    INF,    44,     INF,    0,      INF,
        INF,    INF,    INF,    INF,    INF,    0
    };
    floyd(graph);
    return 0;
}
