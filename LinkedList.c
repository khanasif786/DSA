#include<stdio.h>
#include<stdlib.h>
struct node{
    int info ;
    struct node *link ; 
};

struct node *START = NULL;
struct node *createNode() {
    struct node *n ;
    n = (struct node *)malloc(sizeof(struct node));
    return (n);
}

void insertNode(){
    struct node *temp , *t ;
    temp  = createNode();
    printf("enter a number");
    scanf("%d",&temp -> info);
    temp->link =NULL ; 
    if (START == NULL){
    START = temp;    
    }
    else
    {
      t  = START ; 
      while(t->link!=NULL){
          t = t->link ;  
      }
      t->link = temp ;
    } 
    }

    void deleteNode(){
        struct node *r , *s ; 
        if(START == NULL){
            printf("linked list is empty");
        }
        else{
            r = START ;
            while(r->link!=NULL){
            s = r  ;
            r = r -> link ; 
            }
            free(r);
            s->link = NULL ; 

        }  
    }

    void viewList(){
        struct node *t ; 
        if (START == NULL)
        printf("list is empty");
        else{
            t = START ; 
            while(t != NULL)
            {
                printf("%d " , t -> info);
                t = t -> link ;
            }
        }
    }

    int menu(){
    int ch ; 
    printf("\n1. Add value to the list");
    printf("\n2. Delete last value");
    printf("\n3 . View List");
    printf("\n4. exit");
    printf("\n enter your choice");
    scanf("%d",&ch);
    return (ch);
    }

    void main(){
        while(1){
            switch (menu()){
                case 1:
                insertNode();
                break;
                case 2:
                deleteNode();
                break;
                case 3:
                viewList();
                break;
                case 4:
                exit(0);
                default:
                printf("invalid choice");
            }
            }
        }
    

