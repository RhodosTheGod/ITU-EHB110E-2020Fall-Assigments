#include <stdio.h>

int main(){
    
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    
    int starCountOfLastLine = size*2 -1;
    
    for(int i = 1; i <= size; i++){
        
        int starCountOfThisLine = i * 2 - 1;
        
        int spaceNumber = starCountOfLastLine - starCountOfThisLine;
        
        for(int j = 0; j < (spaceNumber / 2) ; j++){
            printf(" ");
        }
        
        for(int j = 0; j<starCountOfThisLine; j++){
            printf("*");
        }
        
        printf("\n");
    }
    return 0;
}
