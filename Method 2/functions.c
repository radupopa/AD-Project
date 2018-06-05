#include "functions.h"

void find_path( int u, int v, int dist[][V], int pred[][V] ){
    if ( pred[u][v] == v ) {
        printf( "%2d", v );
        return 0;
    }
    find_path( u, pred[u][v], dist, pred );
    printf( " ->%2d", v );
}

void print_path( int dist[][V], int pred[][V] ){
    int i,j;
    printf( "Enter the source node: " );
    scanf( "%d", &i );
    printf( "Enter the destination node: " );
    scanf( "%d", &j );
    printf( "The shortest path between %d and %d is: \n", i, j );
    if ( dist[i][j] == INF ) {
        printf( "%2s\n", "#" );
    }
    find_path( i, j, dist, pred );
    printf( "\nThe weight of the path is: %d", dist[i][j] );
}

void floyd( int graph[][V] ){
    int dist[V][V];
    int i, j, k;

    int pred[V][V];

    for ( i = 0; i < V; i++ ){
        for ( j = 0; j < V; j++ ){
            dist[i][j] = graph[i][j];
            pred[i][j] = i;
        }
    }

    for ( k = 0; k < V; k++ ){
        for ( i = 0; i < V; i++ ){
            for ( j = 0; j < V; j++ ){
                if ( dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = k;
                }
            }
        }
    }

    print_path( dist, pred );
}
