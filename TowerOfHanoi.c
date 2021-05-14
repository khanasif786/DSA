#include<stdio.h>
#include<stdlib.h>

void TOH(int n,char BEG,char AUX,char END){
    if(n!=0){
        TOH(n-1,BEG,END,AUX);
        printf("%c to %c\n",BEG,END);
        TOH(n-1,AUX,BEG,END);
    }
}

void main(){
    int n ;
    char BEG = 'A';
    char AUX = 'B';
    char END = 'C';
    printf("n=?\n");
    scanf("%d",&n);
    TOH(n,BEG,AUX,END);
}