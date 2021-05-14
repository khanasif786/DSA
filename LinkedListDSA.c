//linkedList implimentation 
//Note that deletion occures from first node 
#include<stdio.h>
#include<stdlib.h> // for functioning of malloc and free
struct node
{
    int info ;
    struct node* link;    
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
    temp->link  = NULL;
    if(START == NULL){
        START = temp;
    }
    else{
        t = START;
        while(t->link!=NULL){
            t=t->link;
        }
        t->link = temp;
    }
}

void DeleteNode(){
    struct node *r ,*temp;
    if(START == NULL){
        printf("linkedlist is empty\n");
    }
    else{
     r = START ;
     START = START -> link;
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
            t = t->link;
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