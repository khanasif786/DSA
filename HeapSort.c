#include<stdio.h>
#include<stdlib.h>
struct Heap{
    int *array ;
    int count ;
    int capacity ;
};

struct Heap* CreateHeap(int capacity){
    struct Heap *h = (struct Heap*)malloc(sizeof(struct Heap));
    h->count = 0 ;
    h->capacity = capacity ;
    h->array = (int*)malloc(sizeof(int)*capacity);
    return(h);
}

int LeftChild(struct Heap *h,int i){
    int left = 2*i+1;
    if(left>=h->count)        
        return(-1);                     
    return(left);    
}

int RightChild(struct Heap *h,int i){
    int right = 2*i+2;
    if(right>=h->count)
        return(-1);
    return(right);    
}

void PercolateDown(struct Heap *h, int i){
    int l ,r ,max ,temp ;
    l = LeftChild(h,i);
    r = RightChild(h,i);
    if(l != -1 && h->array[l]>h->array[i])
        max  = l;
    else
        max = i ;
    if(r != -1 && h->array[r]>h->array[max])
        max = r;
    if(max != i){
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp ;
        PercolateDown(h,max);
    }
}

void BuildHeap(struct Heap *h,int A[],int n){
    int i ;
    for(i=0;i<n;i++){
        h->array[i] =A[i];
    }
    h->count = n ;
    for(i=(n-1)/2;i>=0;i--) // doubt
        PercolateDown(h,i);             
}

void HeapSort(int A[] ,int n){
    struct Heap *h = CreateHeap(n);
    int old_size , i , temp , lastvalue ;
    BuildHeap(h,A,n);
    old_size = h->count ;
    for(i=n-1;i>0;i--){
        temp = h->array[0];
        h->array[0] = h->array[h->count -1];
        h->array[h->count -1] = temp ;
        h->count = h->count -1;
        for(int j=(h->count-1)/2;j>=0;j--){
            PercolateDown(h,j);
        }     
    }
    h->count = old_size ;
    for(i=0;i<n;i++){
        printf("%d ",h->array[i]);
    }
    printf("\n");
}

void main(){
    int A[] = {22,34,3,78,47,102,64,99,256,389,172,63,29};
    HeapSort(A,13); //also prints heap itself
}

