#include<stdio.h>

void InsertionSort(int A[], int n){
    int i , j , temp;
    for(i=1;i<n;i++){
        temp = A[i];
        for(j=i-1;j>=0;j--){
            if(A[j]>temp){
                A[j+1] = A[j];
            }
            else
            break;
        }
        A[j+1] = temp ;
    }
}

void main(){
    int A[15] = {2,6,3,8,1,0,5,23,45,32,65,67,56,87,90};
    int n = 15 , i ;
    InsertionSort(A,n);
    for (i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}