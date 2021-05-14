//Insertion Sort
#include<stdio.h>

void InsertionSort(int A[] , int N){
    int i , j , temp ;
    for(i = 1;i<N;i++){
        temp = A[i];
        for(j=i-1;j>=0&&temp<A[j];j--){
           A[j+1] = A[j]; 
        }
        A[j+1] = temp ;
    }
}

void main(){
    int A[] = {22,34,3,78,47,102,64,99,256,389,172,63,29,8};
    InsertionSort(A,14);
    for(int i=0;i<=13;i++){
        printf("%d ",A[i]);
    }
}
