///\file functions.h
///\brief This header file contains all the required
///definitions of the functions used in Dijkstra Algorithm.
///\author Radu Popa
///\date 05.06.2018.

#define MAIN_H_INCLUDED

#include <stdio.h>
#define INF 0x3fffffff
#define V 6
///\def #define V 6
///\brief The number of nodes. Don't forget to change this number with the one generated randomly!

void find_path( int u, int v, int dist[][V], int pred[][V] );
void print_path( int dist[][V], int pred[][V] );
void floyd( int graph[][V] );


