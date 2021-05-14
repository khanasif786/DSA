#include<stdio.h>
#include<string.h> //for strlen() function
void swap(char*,char*);
void permutation(char*,int , int);
void permutation(char*s,int i , int n){
    static int count ; int j ;
    if(i==n){
        count++;
        printf("(%d)%s\t",count,s);
    }
    else
        for(j=i;j<=n;j++){
            swap((s+i),(s+j));
            permutation(s,i+1,n);
            swap((s+i),(s+j));
        }
    }
    

void swap(char*x,char*y){
    char ch ;
    ch  = *x;
    *x = *y;
    *y = ch ;
}

void main(){
    char str[10] ;
    printf("enter a string");
    scanf("%s",str);
    // this can be used also to read string -> fgets(str,20,stdin);
    permutation(str,0,strlen(str)-1);
}