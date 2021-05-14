#include<stdio.h>

int fibonacci(int n);
void main(){
    int n ;
    int i;
    printf("upto what no. you want the Fibonacci series\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("%d ",fibonacci(i));
    }
}

int fibonacci(int n){
if((n==1)||(n==2)){
    return(1);
}
return(fibonacci(n-1) + fibonacci(n-2));
    }
   