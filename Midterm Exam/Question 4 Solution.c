#include <stdio.h>

int main(){

    int size;
    printf("Enter the number of terms :");
    scanf("%d",&size);
    printf("\n");
    
    unsigned long long int sum = 0;
    
    printf("Series: \n");
    
    for(int i = 1; i <= size; i++){
        
        unsigned long long int number = 1;
        
        for(int j= 0;j<i;j++){
        
            printf("9");
            /* We can also print number at the end
             * of main for loop but while
             * working with values bigger than 2^64-1, 
             * uns long long int datatype overflows (naturally).
             * We can preserve at least series output 
             * with this way.
             */
             
            number*=10;
        }
        number--;
        
        printf("\t");
        
        sum+=number;
    }
    
    printf("\nSum of series is: %lld", sum);
    
    return 0;
}
