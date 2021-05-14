#include <stdio.h> 
#include <time.h> 
int m[9999][999]; 
  
void main(){ 
    int i, j; 
    clock_t start, stop; 
    double d = 0.0; 
  
    start = clock(); 
    int count = 0 ;
    for (i = 0; i < 9999; i++) {
        for (j = 0; j < 999; j++) {
            m[i][j] = 2 ;//m[i][j] + (m[i][j] * m[i][j]); 
            count = count + 1 ;}}
  
    stop = clock(); 
    d = (double)(stop - start) / CLOCKS_PER_SEC; 
    printf("\nThe run-time of row major order is %lf ", d); 
    printf("and iteration is %d\n",count);
    count = 0 ;
    start = clock(); 
    for (j = 0; j < 999; j++) {
        for (i = 0; i < 9999; i++) {
            m[i][j] = 2 ;//m[i][j] + (m[i][j] * m[i][j]); 
            count = count + 1 ;}}
  
    stop = clock(); 
    d = (double)(stop - start) / CLOCKS_PER_SEC; 
    printf("The run-time of column major order is %lf ", d); 
    printf("and iteration is %d\n",count);
} 