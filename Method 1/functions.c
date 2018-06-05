///\file functions.c
///\brief This file contains all the functions needed
///in Dijkstra Algorithm to find the shortest path between two nodes.
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

int findMin( int x, int y ){
    ///\fn int findMin( int x, int y )
    ///\brief This function returns the minimum value between two numbers.
    ///\param a First integer
    ///\param b Second integer
    ///
    if( x < y ){
        return x;
    }
    return y;
}

int checkMarked( int n, int markedNodes[], int markedNodesIndex ){
    ///\fn int checkMarked( int n, int markedNodes[], int markedNodesIndex )
    ///\brief This function checks if the vertex is marked.
    ///\param v integer
    ///\param markedNodes[] array of integers
    ///\param markedNodesIndex integer
    int iterator = 0;
    for( iterator = 0; iterator < markedNodesIndex; iterator++ ){
        if( n == markedNodes[iterator] ){
            return 1;
        }
    }
    return 0;
}

void dijkstra( int graph[V][V], int source, int destination ){
    ///\fn void dijkstra( int graph[V][V], int source, int destination )
    ///\brief This function finds the shortest path between the source and the destination nodes.
    ///\param graph[][] matrix
    ///\param source integer
    ///\param destination integer
    ///variables
    int i;
    int r;
    int c;
    int tempC;
    int min;
    int currVertex;
    int edgeWt = 0;
    int destValue = 0;
    int markedValue = 0;
    int wtTableR = 0;
    int markedNodesIndex = 0;

    ///array containing vertices in the shortest path
    int shortestPathNodes[V] = {-1};
    int shortestPathNodesIndex = 0;

    ///this matrix stores the weight of the edges
    int weightTable[V][V];
    for( r = 0; r < V; r++ ){
        for( c = 0; c < V; c++ ){
            weightTable[r][c] = INF;
        }
    }
    weightTable[wtTableR++][source] = 0;

    ///nodes that are marked
    int markedNodes[V] = {-1};
    markedNodes[markedNodesIndex++] = source;
    currVertex = source;

    ///find the shortest path
    while( currVertex != destination ){
        ///copy the marked values to the next row of weightTable
        for( i = 0; i < markedNodesIndex; i++ ){
            c = markedNodes[i];
            weightTable[wtTableR][c] = weightTable[wtTableR - 1][c];
        }
        ///find the weight from the current node to all he other
        ///nodes that are directly connected and not yet marked
        for( c = 0; c < V; c++ ){
            if( c != currVertex && !checkMarked(c, markedNodes, markedNodesIndex) ){
                edgeWt = graph[currVertex][c];
                destValue = weightTable[wtTableR - 1][c];
                markedValue = weightTable[wtTableR][currVertex];

                min = findMin( destValue, markedValue + edgeWt );

                weightTable[wtTableR][c] = min;
            }
        }

        ///find the minimum unmarked nodes on the current row
        min = INF;
        for( c = 0; c < V; c++ ){
            if( !checkMarked(c, markedNodes, markedNodesIndex) ){
                if( weightTable[wtTableR][c] < min ){
                    min = weightTable[wtTableR][c];
                    tempC = c;
                }
            }
        }

        ///found a node to be marked
        markedNodes[markedNodesIndex++] = tempC;
        currVertex = tempC;

        ///update the variables
        wtTableR++;
    }

    ///compute shortest path nodes
    c = destination;
    shortestPathNodes[shortestPathNodesIndex++] = c;
    markedValue = weightTable[wtTableR - 1][destination];
    for( r = wtTableR - 2; r >= 0; r-- ){
        if( weightTable[r][c] != markedValue ){
            c = markedNodes[r];
            markedValue = weightTable[r][c];
            shortestPathNodes[shortestPathNodesIndex++] = c;
        }
    }

    ///display the shortest path and its weight
    printf("The shortest path between %d and %d is: \n", source, destination);
    for( i = shortestPathNodesIndex - 1; i >= 0; i-- ){
        printf( "%d", shortestPathNodes[i] );
        if( i > 0 ){
            printf(" --> ");
        }
    }
    printf( "\nThe weight of the path is: %d\n", weightTable[wtTableR - 1][destination] );
}
