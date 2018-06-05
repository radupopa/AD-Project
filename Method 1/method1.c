#include <stdio.h>
#include <stdlib.h>
#define INF 0x3fffffff
#define V 4

int findMin( int x, int y ){
    if( x < y ){
        return x;
    }
    return y;
}

int checkMarked( int n, int markedNodes[], int markedNodesIndex ){
    int iterator = 0;
    for( iterator = 0; iterator < markedNodesIndex; iterator++ ){
        if( n == markedNodes[iterator] ){
            return 1;
        }
    }
    return 0;
}

void dijkstra( int graph[V][V], int source, int destination ){
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

    int shortestPathNodes[V] = {-1};
    int shortestPathNodesIndex = 0;

    int weightTable[V][V];
    for( r = 0; r < V; r++ ){
        for( c = 0; c < V; c++ ){
            weightTable[r][c] = INF;
        }
    }
    weightTable[wtTableR++][source] = 0;

    int markedNodes[V] = {-1};
    markedNodes[markedNodesIndex++] = source;
    currVertex = source;

    while( currVertex != destination ){
        for( i = 0; i < markedNodesIndex; i++ ){
            c = markedNodes[i];
            weightTable[wtTableR][c] = weightTable[wtTableR - 1][c];
        }

        for( c = 0; c < V; c++ ){
            if( c != currVertex && !checkMarked(c, markedNodes, markedNodesIndex) ){
                edgeWt = graph[currVertex][c];
                destValue = weightTable[wtTableR - 1][c];
                markedValue = weightTable[wtTableR][currVertex];

                min = findMin( destValue, markedValue + edgeWt );

                weightTable[wtTableR][c] = min;
            }
        }

        min = INF;
        for( c = 0; c < V; c++ ){
            if( !checkMarked(c, markedNodes, markedNodesIndex) ){
                if( weightTable[wtTableR][c] < min ){
                    min = weightTable[wtTableR][c];
                    tempC = c;
                }
            }
        }

        markedNodes[markedNodesIndex++] = tempC;
        currVertex = tempC;

        wtTableR++;
    }

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

    printf("The shortest path between %d and %d is: \n", source, destination);
    for( i = shortestPathNodesIndex - 1; i >= 0; i-- ){
        printf( "%d", shortestPathNodes[i] );
        if( i > 0 ){
            printf(" --> ");
        }
    }
    printf( "\nThe weight of the path is: %d\n", weightTable[wtTableR - 1][destination] );
}

int main(){
    int graph[V][V] = {
            {0, 5, 10, INF},
            {5, 0, 4, 11},
            {10, 4, 0, 5},
            {INF, 11, 5, 0}
    };

    int source;
    int destination;
    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter the destination node: ");
    scanf("%d", &destination);

    dijkstra(graph, source, destination);

    return 0;
}



