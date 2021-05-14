#include<stdio.h>
#include<stdlib.h>

int fact(int n){
    if(n==1)
        return(1);
    else
        return(n*fact(n-1));
}

void main(){
    int n ;
    printf("enter a number\n");
    scanf("%d",&n);
    printf("%d! = %d",n,fact(n));
}