//AdjacencyList Implimentation Method for Graph
//code is only Prototype without driver code(main function)
//its a directed Graph(with Direction)
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int vertexNo
    struct ListNode *next ;
};

struct Graph{
    int V ;
    int E ;
    struct ListNode *adj;
};

struct Graph* adjMatrixOfGraph(){
    int i  ,x , y ;
    struct ListNode *temp , *t ;
    struct Grapg *G ;
    G = (struct Graph*)malloc(sizeof(struct Graph));
    printf("enter no. of vertex and no. of edges");
    scanf("%d %d",&G->V,&G->E);
    G->adj = (struct ListNode*)malloc(G->V*sizeof(struct ListNode));
    for(i=0;i<G->V;i++){
        G->adj[i]->vertexNo =  i ;
        G->adj[i]->next = G->adj+i ;
    }
    for(i=0;i<G->E;i++){
        printf("enter edge (source node and destination node)");
        scanf("%d %d",&x,&y);
        temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp->vertexNo = y ;
        temp->next = G->adj[x];
        t = G->adj[x];
        while(t->next!=G->Adj[x]){
            t = t->next;
        }
        t->next = temp ;
    }
}