///\file functions.c
///\brief This file contains all the functions needed
///in Floyd Algorithm to find the shortest path between two nodes.
///
///\author Radu Popa
///\date 6/05/2018

#include "functions.h"
#define INF 0x3fffffff
#define V 6
///\def #define V 6
///\brief The number of nodes. Don't forget to change this number with the one generated randomly!
///\def #define INF 0x3fffffff
///\brief A constant to represent infinity. It is assumed that no edge will have this weight.

void find_path( int u, int v, int dist[][V], int pred[][V] ){
    ///\fn void find_path( int u, int v, int dist[][V], int pred[][V] )
    ///\brief This functions holds information about the path.
    ///\param u integer
    ///\param v integer
    ///\param dist[][] array of integers
    ///\param pred[][] array of integers
    if ( pred[u][v] == v ) {
        printf( "%2d", v );
        return 0;
    }
    find_path( u, pred[u][v], dist, pred );
    printf( " ->%2d", v );
}

void print_path( int dist[][V], int pred[][V] ){
    ///\fn A function to print the shortest path and its weight.
    ///\param dist[][] array of integers
    ///\param pred[][] array of integers
    int i;
    int j;
    ///The source and the destination nodes.
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
    ///\fn void floyd( int graph[][V] )
    ///\brief This function finds the shortest path between the source and the destination nodes.
    ///\param graph[][] array of integers
    ///variables
    int dist[V][V]; ///\var dist[][] is the solution matrix that holds the shortest distance between the nodes.
    int i;
    int j;
    int k;

    int pred[V][V];

    ///initialize the solution matrix same as the input graph matrix.
    for ( i = 0; i < V; i++ ){
        for ( j = 0; j < V; j++ ){
            dist[i][j] = graph[i][j];
            pred[i][j] = i;
        }
    }

    for ( k = 0; k < V; k++ ){
        ///pick all the nodes as source
        for ( i = 0; i < V; i++ ){
            ///pick all the nodes as destination for the above picked source
            for ( j = 0; j < V; j++ ){
                ///if the node k is on the shortest path from i to j, update dist[i][j].
                if ( dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = k;
                }
            }
        }
    }

    ///print the shortest distance
    print_path( dist, pred );
}
