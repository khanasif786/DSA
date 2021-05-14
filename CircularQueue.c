//CircularQueue code
#include<stdio.h>
#include<stdlib.h>
struct CircularQueue{
    int front,rear ;
    int capacity;
    int *array ;
};
struct CircularQueue* CreateQueue(int capacity){
    struct CircularQueue * Q  = malloc(sizeof(struct CircularQueue));
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

int isEmptyQueue(struct CircularQueue* Q){
 return(Q->front==-1);
}

int isFullQueue(struct CircularQueue *Q){
    // this is also another suitable conditional check (both can be used independently)
    return((Q->rear+1)%Q->capacity==Q->front); //if(front==0||rear = capacity - 1) || (front = rear + 1) 
}

int QueueSize(struct CircularQueue* Q){
    //if(front<=rear)
    //elements = rearIndex + 1
    //else
    //elements = frontIndex to lastIndex + zeroIndex  to rearIndex   
    return((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}

void enqueue(struct CircularQueue *Q, int data){
    if(isFullQueue(Q))
    printf("overflow");
else{
    // Q->rear++;
    // if Q->rear == capacity
    // Q-rear = 0 
    // Q-array[Q->rear] = data ;
    // if(Q-front ==  -1)
    // Q->front = Q->rear ;
    Q->rear = (Q->rear+1)%Q->capacity;
    Q->array[Q->rear] = data ;
    if(Q->front == -1)
    Q->front = Q->rear;
}
}

int dequeue(struct CircularQueue *Q){
    int data = -1 ;
    if(isEmptyQueue(Q)){
        printf("Queue is empty");
        return(-1);
    }
    else{
        data = Q->array[Q->front];
        if(Q->front == Q->rear)
        Q->front = Q->rear = -1 ; 
        else
        // if(front<rear)
        // Q->front++;
        // else
        // Q->front++;
        // Q->front == capacity ; 
        // Q->front = 0 ;
        Q->front = (Q->front +1)%Q->capacity;
    }
    return(data);
}

void main(){
    int choice , item ;
    struct CircularQueue* Queue = CreateQueue(3);
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
        if(Queue->front <= Queue->rear){
            if ((Queue->front == Queue->rear) && (Queue->front == -1)){
              printf("Queue is empty");
              break;
            }
          for(int i = Queue->front ; i <= Queue->rear ; i++){
              printf(" %d\n",Queue->array[i]);
          }          
        }
        else{
            for(int  i  = 0 ; i <= Queue->rear ;i++ ){
             printf(" %d\n",Queue->array[i]);   
            }
            for(int i  = Queue->front ; i < Queue->capacity ;i++ )
            {
             printf(" %d\n",Queue->array[i]);   
            }
        }
        break;
    }
}    
}
