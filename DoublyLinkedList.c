// Doubly linked list implimentation
// NOTE: insertion and deletion as first node ONLY
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info ;
    struct node *prev , *next;    
};
struct node *START = NULL ;
struct node* CreateNode(){
    struct node *n;
    n=(struct node*)malloc(sizeof(struct node));
    return(n);
}
void InsertNode(){
    struct node *temp,*t;
    temp = CreateNode();
    printf("enter a number\n");
    scanf("%d",&temp->info);
    temp->next  = NULL;
    temp->prev = NULL;
    if(START == NULL){
        START = temp;
    }
    else{
        t = START ;
        START = temp;
        temp->next = t;
        t->prev = temp ;
    }
}

void DeleteNode(){
    struct node *r ,*temp;
    if(START == NULL){
        printf("linkedlist is empty\n");
    }
    else{
     r = START ;
     START = START -> next;
     if(START!=NULL)
        START->prev = NULL;
     free(r);
    }
}
void ViewList(){
    struct node *t;
    if (START==NULL){
        printf("list is empty\n");
    }
    else{
        t = START ;
        while(t!=NULL){
            printf("%d ",t->info);
            t = t->next;
        }       
    }
}
int menu(){
    int ch ;
    printf("\n1.add value to the list");
    printf("\n2. delete value from the list");
    printf("\n3. view list");
    printf("\nEnter your choice\n");
    scanf("%d",&ch);
    return(ch);
}
void main(){
    while(1){
        switch(menu()){
            case 1:
            InsertNode();
            break;
            case 2:
            DeleteNode();
            break;
            case 3:
            ViewList();
            break;
            default:
            printf("invalid choice\n");
        }
    }
}
