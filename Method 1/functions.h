///\file functions.h
///\brief This header file contains all the required
///definitions of the functions used in Dijkstra Algorithm.
///\author Radu Popa
///\date 05.06.2018.


#define MAIN_H_INCLUDED

#include <stdio.h>
#define V 6
///\def #define V 6
///\brief The number of nodes. Don't forget to change this number with the one generated randomly!

int findMin( int x, int y );
int checkMarked( int n, int markedNodes[], int markedNodesIndex );
void dijkstra( int graph[V][V], int source, int destination );
