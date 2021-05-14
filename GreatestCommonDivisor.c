#include<stdio.h>
int GCD(int , int);
void main(){
 int  x , y , result ; 
 printf("enter 2 numbers to know their GCD\n");
 scanf("%d\n%d",&x,&y);
 result = GCD(x,y);
 printf("\nGCD of %d and %d is : %d" , x , y, result);
}

int GCD(int x, int y){
    if(x==y){
        return(x);
    }
    else if (x%y ==  0){
        return(y);
    }
    else if (y%x==0){
        return(x);
    }
    else if (x>y){
        return(GCD(x%y,y));
    }
    else{
        return(GCD(y%x,x));
    }
}