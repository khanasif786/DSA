//Quick Sort
#include<stdio.h>

void quick(int A[], int N, int BEG , int END , int *LOCPTR){
    int LEFT ,RIGHT ,temp  ;
    LEFT = BEG ; RIGHT = END ;
    *LOCPTR = BEG ;
    
step2:
    while(A[*LOCPTR]<=A[RIGHT]&&*LOCPTR!=RIGHT){
        RIGHT--;
    }
    if(*LOCPTR==RIGHT)
        return;
    if(A[*LOCPTR]>A[RIGHT]){
        temp = A[*LOCPTR];
        A[*LOCPTR] = A[RIGHT];
        A[RIGHT] = temp ;
        *LOCPTR = RIGHT ;
    }
    goto step3 ;
step3:    
    while(A[*LOCPTR]>=A[LEFT]&&(*LOCPTR)!=LEFT){
        LEFT++;
    }
    if(*LOCPTR==LEFT)
        return;
    if(A[*LOCPTR]<A[LEFT]){
        temp = A[*LOCPTR];
        A[*LOCPTR] = A[LEFT];
        A[LEFT] = temp ;
        *LOCPTR = LEFT ;
    }
    goto step2;    
}

void quick_sort(int A[] , int N){
    int BEG ,END ,LOC,TOP = -1 ;
    int LOWER[20] , UPPER[20] ;
    if(N>1){
        TOP++;
        LOWER[TOP] = 0 ;
        UPPER[TOP] = N-1;
    }
    while(TOP!=-1){
        BEG = LOWER[TOP];
        END = UPPER[TOP];
        TOP--;
        quick(A,N,BEG,END,&LOC);
        if(BEG<LOC-1){
            TOP++;
            LOWER[TOP] = BEG ;
            UPPER[TOP] = LOC -1 ;
        }  
        if(LOC + 1 <END){
            TOP++;
            LOWER[TOP] = LOC + 1 ;
            UPPER[TOP] = END ;
        }  
    }
}

void main(){
    int A[] = {22,34,3,78,47,102,64,99,256,389,172,63,29,8};
    quick_sort(A,14);
    for(int i=0;i<=13;i++){
        printf("%d ",A[i]);
    }
}