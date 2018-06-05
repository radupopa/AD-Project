#include <stdio.h>
#include <time.h>

int main(){
    int n,adj[100][100],i,j,max,node1,node2,weight;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            adj[i][j] = 0;
        }
    }
    max = (n * (n - 1)) / 2;
    for (i = 1; i <= max; i++){
        printf("\nEdge %d\n", i);
        printf("Node 1: ");
        scanf("%d", &node1);
        if(node1 == -1){
            break;
        }
        printf("Node 2: ");
        scanf("%d", &node2);
        printf("Weight: ");
        scanf("%d", &weight);
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
