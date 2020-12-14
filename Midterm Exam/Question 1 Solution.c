#include <stdio.h>
#include <math.h>

float calc (int x, int c, int v);

int main(){
    int x,c,v;
    printf("Enter x: ");
    scanf("%d",&x);
    
    printf("\nEnter c: ");
    scanf("%d",&c);
    
    printf("\nEnter v: ");
    scanf("%d",&v);
    
    float f = calc(x,c,v);
    printf("\nResult is %f",f );
    return 0;
}

float calc (int x, int c, int v){
    float z;
    
    z = ((float)(x+c)) / (3 - (float)sqrt(1 + (((float)(v * v)) / (c * c))));
    //I casted every number to float to aviod any fraction loss.
    return z;
}
