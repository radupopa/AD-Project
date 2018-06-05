#define MAIN_H_INCLUDED

#include <stdio.h>
#define INF 0x3fffffff
#define V 6

void find_path( int u, int v, int dist[][V], int pred[][V] );
void print_path( int dist[][V], int pred[][V] );
void floyd( int graph[][V] );


