#define MAIN_H_INCLUDED

#include <stdio.h>
#define V 6

int findMin( int x, int y );
int checkMarked( int n, int markedNodes[], int markedNodesIndex );
void dijkstra( int graph[V][V], int source, int destination );
