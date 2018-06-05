#include <stdio.h>
#include "functions.h"
#define INF 0x3fffffff
#define V 6


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
