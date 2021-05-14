#include<stdio.h>
#include<string.h>
void bin(int , char[]);
void bin(int n , char A[]){ // char A[] = B[20] ; <RIGHT> | char A[] ; <WRONG> or <error>
    if(n<1)
        printf("\n%s",A);
    else{
        A[n-1] = '0';
        bin(n-1,A);
        A[n-1] = '1';
        bin(n-1,A);
    }
}

void main(){
    char A[4];
    A[3] =  '\0';
    bin(3,A);
}