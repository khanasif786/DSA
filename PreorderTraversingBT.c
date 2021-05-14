#include<stdio.h>
#include<stdlib.h>

struct BTnode{
    int info ;
    struct BTnode *left;
    struct BTnode *right;
};
struct BTnode *START == NULL;

struct BTnode* CreateNode(){
    struct BTnode *n;
    n = (struct BTnode *)malloc(sizeof(struct BTnode));
    return(BTnode)
}

void InsertNode(int data,struct BTnode* Localroot){
    printf("Enter 1 for Right and 2 for Left\n");
    scanf("%d",&(int choice));
    if(choice == 1){
    if(Localroot->right == NULL){
        struct BTnode *temp  = CreateNode();
        Localroot->right = temp ;
        temp->right = NULL;
        temp->left = NULL ;
        printf("insert Value\n");
        scanf("%d",temp->info);
        printf(" value inserted..");
    }
    else{
        InsertNode(data,Localroot);
    }

    }
    else{
    if(Localroot->left == NULL){
        struct BTnode *temp  = CreateNode();
        Localroot->left = temp ;
        temp->right = NULL;
        temp->left = NULL ;
        printf("insert Value\n");
        scanf("%d",temp->info);
        printf(" value inserted..");        

    }
    else{
        InsertNode(data,Localroot);
    }        
    }
    
}


void main(){
struct BTnode *a = malloc(sizeof(struct BTnode));
a->info = 1 ;
a->left = malloc(sizeof(struct BTnode));
a->right = malloc

}