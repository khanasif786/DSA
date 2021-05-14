//LinearQueue code
#include<stdio.h>
#include<stdlib.h>
struct LinearQueue{
    int front,rear ;
    int capacity;
    int *array ;
};
struct LinearQueue* CreateQueue(int capacity){
    struct LinearQueue * Q  = malloc(sizeof(struct LinearQueue));
    if(!Q) // if by some reason malloc not works then do a NULL return
    return(NULL);
    Q->capacity = capacity ;
    Q->front = -1 ;
    Q->rear = -1 ;
    Q->array = malloc(Q->capacity*sizeof(int));
    if(!Q->array) // if by some reason malloc not works then do a NULL return
    return(NULL);
    return(Q);
}

int isEmptyQueue(struct LinearQueue* Q){
 return(Q->front==-1);
}

int isFullQueue(struct LinearQueue *Q){
    return(Q->rear == (Q->capacity - 1)); 
}

int QueueSize(struct LinearQueue* Q){
    if(Q->rear == -1 && Q->front == -1){
        return(0);
    }  
    return(((Q->rear + 1) - (Q->front)));
}

void enqueue(struct LinearQueue *Q, int data){
    if(isFullQueue(Q))
    printf("overflow");
else{
    if(isEmptyQueue(Q)){
        Q->rear =  0 ;
        Q->front =  0 ;
    }
    else
    Q->rear = Q->rear + 1 ;
 Q->array[Q->rear] = data ;
}
}
int dequeue(struct LinearQueue *Q){
    int data = -1 ;
    if(isEmptyQueue(Q)){
        printf("Queue is empty");
        return(-1);
    }
    else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear){
            Q->front = -1;
            Q->rear = -1 ;
        }
        else
        Q->front = Q->front + 1 ;

    }
    return(data);
}
void main(){
    int choice , item ;
    struct LinearQueue* Queue = CreateQueue(3);
while(1){
    printf("1.Insert 2.Delete 3.Display\nEnter your Choice\n" );
    scanf("\n%d",&choice);

    switch(choice){
        case 1:
        printf("enter a number\n");
        scanf("%d",&item);
        enqueue(Queue,item);
        break;
        case 2:
        dequeue(Queue);
        break;
        case 3:
        if (!isEmptyQueue(Queue)){
        for(int i = Queue->front ; i <= Queue->rear; i++){
            printf("%d\n",Queue->array[i]);
        }
        }
        else
        printf("Queue is empty");
        break;
    }
}    
}
