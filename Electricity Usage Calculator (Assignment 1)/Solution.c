#include <stdio.h>

float GetBillAmountForInterval(int usage, int min, int max, float multiplier);
float GetBillAmountPositiveInfinity(int usage, int min, float multiplier);
int main(){

    //Variable Declarations
    float billAmount;
    float surcharge;
    int electricityUsage;

    //Input
    printf("Enter consumption amount: ");
    scanf("%d", &electricityUsage);

    if(electricityUsage <= 0){
        printf("INVALID AMOUNT");
        return 1;
    }

    //Calculation
    billAmount = GetBillAmountForInterval(electricityUsage , 1, 199, 1.5f)
                  +  GetBillAmountForInterval(electricityUsage , 200, 349, 1.7f)
                  +  GetBillAmountForInterval(electricityUsage , 350, 499, 1.8f)
                  +  GetBillAmountPositiveInfinity(electricityUsage , 500, 2.0f);



    printf("Total bill is: ");
    printf("%f\n",billAmount);

    if(electricityUsage > 800){
        surcharge = billAmount * (3.0f / 10);

        printf("Surcharge is: ");
        printf("%f\n",surcharge);

        printf("Total bill with surcharge is: ");
        printf("%f",(surcharge + billAmount));
    }
}
//min and max inclusive
float GetBillAmountForInterval(int usage, int min, int max, float multiplier){

    if (usage < min) return 0.0f;


    if((usage - min) >= max){
        return ((float)(max - min + 1)) * multiplier;
    }
    else {
        return ((float)(usage - min + 1)) * multiplier;
    }
}
//min inclusive
float GetBillAmountPositiveInfinity(int usage, int min, float multiplier){

    if (usage < min) return 0.0f;
    return ((float)(usage - min + 1)) * multiplier;
}