// Selection Sort
#include<stdio.h>

int Minimum(int a[] , int  k , int n){
    int min_index ;
    for(int i=k;i<=n-1;i++){
        if(i==k)
            min_index = i;  
        else{
            if(a[i] < a[min_index])
                min_index = i;
        }  
    }
    return min_index ;
}

void Swap(int *a,int *b){
    int c ;
    c = *a ;
    *a = *b ;
    *b = c ;
}

void SelectionSort(int a[] , int n){
    int min_index ;
    for(int i=0;i<=n-1;i++){
        min_index = Minimum(a,i,n);
        Swap(&a[i],&a[min_index]);
    }
}

void main(){
    int A[14] = {22,34,3,78,47,102,64,99,256,389,172,63,29,8};
    SelectionSort(A,14);
    for(int i=0;i<=13;i++){
        printf("%d ",A[i]);
    }
}
