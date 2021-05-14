//AdjacencyMatrix Implimentation Method for Graph
//code is only Prototype without driver code(main function)
//its a non-directed Graph(without Direction)
#include<stdio.h>
#include<stdlib.h>

struct Graph{
    int V ;
    int E ;
    int *adj;
};

struct Graph* adjMatrixOfGraph(){
    int u , v , i ; // malloc kaa return type void* hota hai bydefault
    struct Graph *G = (struct Graph*)malloc(sizeof(struct Graph));
    printf("enter number of nodes and number of edges");
    scanf("%d %d",&G->V,&G->E);
    G->adj = malloc(sizeof(int)*(G->V)*(G->V));
    for(u=0;u<G->V;u++){
        for(v=0;v<G->V;v++){
            G->adj[u][v] = 0;
        }
    }
    printf("enter node and edge connections");
    for(i=0;i<G->E;i++){
        scanf("%d %d",&u,&v);
        G->adj[u][v] = 1;
        G->adj[v];
    }
    return(G);
}

