#include<stdio.h>

void merge(int A[] , int n1 , int index1 , int B[], int n2 , int index2 , int C[]  , int index  ){
    while(n1&&n2){
        if(A[index1] < B[index2]){
             C[index] = A[index1];
             index ++ ; 
             index1 ++ ;
             n1-- ; 
             
        }
        else{
            C[index] = B[index2];
            index++;
            index2++;
            n2--;
        }

    }
    while(n1){
            C[index] = A[index1];
            index++;
            index1++;
            n1--;

    }

    while(n2){
        C[index] = B[index2];
        index++;
        index2++;
        n2--;
    }

}


void mergepass(int A[] , int N , int sub_array_size , int B[]){
int Q , S , R ;
Q = N/2*sub_array_size ; 
S = 2*sub_array_size*Q ; 
R = N - S ; 
int j , LB ; 

for(j = 0 ; j<Q ; j++){
    LB = 2*j*sub_array_size ;
    merge(A , sub_array_size , LB , A , sub_array_size , LB + sub_array_size , B , LB);
}

if(R<=sub_array_size){
  for(j=0 ; j<R ; j++){
      B[j+S]  = A[j+S];
  }
}

else{
    merge(A , sub_array_size , S , A , R - sub_array_size , S + sub_array_size ,B ,S );
}  

}



void merge_sort(int A[] ,int array_size ){

int sub_array_size = 1; 
int B[array_size] ; 

while(sub_array_size < array_size){
    mergepass(A , array_size , sub_array_size , B);
    mergepass(B,array_size , 2*sub_array_size , A);
    sub_array_size = sub_array_size*4 ;
}

}



int main()
{    
    int  i , j , array_size = 13 ; 
    int A[13]  = { 13 , 15 , 2 , 97 , 36 , 25 , 68, 7, 88 , 72 ,69 , 90 , 47 } ; 

    printf("this is the original array");
    for(i = 0 ;  i <= (array_size - 1) ; i++){
        printf(" %d  , ",A[i]);
    }

    merge_sort( A , array_size);
    printf("\n");
    for(j = 0 ;  j <= (array_size - 1) ; j++){
        printf(" %d  , ",A[i]);
    }    
    return(0);
}