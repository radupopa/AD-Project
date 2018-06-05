///\file method1.c
///\brief C program to find the shortest path between two nodes, using Dijkstra Algorithm.
///\author Radu Popa
///\date 05.06.2018

#include <stdio.h> ///> printf(), scanf()
#include "functions.h" ///> dijkstra()
#define INF 0x3fffffff
#define V 6
///\def #define V 6
///\brief The number of nodes. Don't forget to change this number with the one generated randomly!
///\def #define INF 0x3fffffff
///\brief A constant to represent infinity. It is assumed that no edge will have this weight.


int main(){
    ///\fn int main()
    ///\brief Main function.
    /// Function call of dijkstra imported from functions.h
    ///\var graph A matrix holding the weight of the edges.
    ///Compute it using the random generator program, then copy the adjacency matrix here.

    int graph[V][V] = {
         0,      135,    INF,    87,     157,    INF,
        135,    0,      128,    INF,    INF,    INF,
        INF,    128,    0,      118,    44,     INF,
        87,     INF,    118,    0,      INF,    INF,
        157,    INF,    44,     INF,    0,      INF,
        INF,    INF,    INF,    INF,    INF,    0,
    };

    ///the source and the destination nodes
    int source;
    int destination;
    printf("Enter the source node: ");
    scanf("%d", &source);
    printf("Enter the destination node: ");
    scanf("%d", &destination);

    ///find the shortest path
    dijkstra(graph, source, destination);

    return 0;
}



