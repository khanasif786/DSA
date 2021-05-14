#include<stdio.h>
#include<stdlib.h>


struct StackArray {
    int top ; 
    int capacity ;
    int *ArrayPointer ;
};

int isEmpty(struct StackArray* StackPointer);
int isFull(struct StackArray* StackPointer);
void pop(struct StackArray* StackPointer);
void push(struct StackArray* StackPointer,int item);
struct StackArray* CreateStack(int cap);

void main(){
struct StackArray * Stack ; 
int choice  , item  ;
Stack = CreateStack(3);
while(1){
    printf("1.PUSH 2.POP 3.Display\nEnter your Choice\n" );
    scanf("\n%d",&choice);

    switch(choice){
        case 1:
        printf("enter a number\n");
        scanf("%d",&item);
        push(Stack,item);
        break;
        case 2:
        pop(Stack);
        break;
        case 3:
        if (!isEmpty(Stack)){
         printf("\nstack is\n");
        for(int i=0;i<=Stack->top;i++){
         printf("%d",Stack->ArrayPointer[i]);
        }
        }
        else
        printf("stack is empty\n");
        break;
    }
}
}

struct StackArray* CreateStack(int cap){
struct StackArray* StackPointer ;
StackPointer  = malloc(sizeof(int)*cap);
StackPointer->capacity = cap ;
StackPointer->top = -1 ;
StackPointer->ArrayPointer = malloc(sizeof(int)*cap);
return(StackPointer);
}

void push(struct StackArray* StackPointer,int item){
if(!isFull(StackPointer)){
StackPointer->ArrayPointer[(StackPointer->top)+1] = item ;
StackPointer->top++;
printf("Succesfully Pushed item into the Stack\n");
}
else
printf("stack is full\n");
}

void pop(struct StackArray* StackPointer){
int item ;
if(!isEmpty(StackPointer)){
item  = StackPointer->ArrayPointer[StackPointer->top];
StackPointer->top--; 
printf("popped item is %d\n",item);
}
else
printf("stack is empty\n");
}

int isFull(struct StackArray* StackPointer){
if(StackPointer->top == (StackPointer->capacity - 1))
return(1);
else
return(0);

}

int isEmpty(struct StackArray* StackPointer){
if(StackPointer->top == -1)
return(1);
else
return(0);
}