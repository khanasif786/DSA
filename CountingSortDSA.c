// Counting Sort
#include<stdio.h>

void CountingSort(int A[], int N , int B[],int K)// N == elemets ; K == range of elements
{
    int i, j,C[K];
    for(i=0;i<K;i++)
        C[i] = 0 ;
    for(j=0;j<N;j++)
        C[A[j]] = C[A[j]] + 1 ;
    for(i=1;i<K;i++) // cumulative frequency
        C[i] = C[i] + C[i-1];
    for(j=N-1;j>=0;j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]]-1;
    }

}

void main(){
    int A[] = {5,9,4,5,3,6,8,5,4,8,7,4,6,9,7};
    int B[15] , i ;
    int K= 10 ; // range of elements
    int N = 15 ;
    CountingSort(A,N,B,K);
    for(i=0;i<N;i++)
        printf("%d ",B[i]);
}