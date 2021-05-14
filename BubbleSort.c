//Bubble Sort
#include<stdio.h>
void Swap(int *,int *);
void BubbleSort(int * , int);
void BubbleSort(int A[] , int n){
    for(int i=0;i<=n-2;i++){
        for(int j=i;j<=n-1;j++){
            if(A[i]>A[j]){
                Swap(&A[i],&A[j]);  
            }
        }
    }
}

void Swap(int *a,int *b){
    int c ;
    c = *a ;
    *a = *b ;
    *b = c ;
}
void main(){
    int A[5] = {22,34,3,78,47};
    BubbleSort(A,5);
    for(int i=0;i<=4;i++){
        printf("%d ",A[i]);
    }
}
