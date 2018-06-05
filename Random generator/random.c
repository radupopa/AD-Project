#include <stdio.h>
#include <time.h>
#define MAX_NODE 60

int main(){
    int n,adj[100][100],i,j,max,node1,node2,weight;

    srand(time(NULL));
    n = rand()%MAX_NODE;
    printf("no of nodes %d\n", n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            adj[i][j] = 0;
        }
    }
    max = (n * (n - 1)) / 2;
    for (i = 1; i <= max; i++){
        printf("\nEdge %d\n", i);
        node1 = rand()%n;
        printf(" Node 1: %d ", node1);

        node2 = rand()%n;
        printf(" Node 2: %d ", node2);

        weight = rand()%200;
        printf(" Weight: %d ", weight);

        if(node1 > n || node2 > n){
            printf("Invalid");
        } else{
            adj[node1][node2] = weight;
            adj[node2][node1] = weight;
        }

    }

    printf("The adjacency matrix: \n");
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            if(i == j){
                printf("\t0");
            }else
            if(adj[i][j] == 0){
                printf("\tINF");
            }else{
            printf("\t%d", adj[i][j]);
            }

        }
        printf("\n");
    }
}
