#include <stdio.h>

int main(){
    int windSpeed;
    
    printf("Enter wind speed: ");
    scanf("%d",&windSpeed);
    printf("\nWind Type: ");

    if(windSpeed<1){
        printf("Calm");     
    }
    else if(windSpeed<6){
        printf("Light");
    }
    else if(windSpeed<31){
        printf("Breeze");
    }
    else if(windSpeed<51){
        printf("Storm");
    }
    else{
        printf("Hurricane");
    }


    return 0;
}
