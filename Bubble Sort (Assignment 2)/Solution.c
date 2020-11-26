#include <stdio.h>

int Reorder(int* min, int* max);

//First index represents columns, second one represents rows
int matrix[10][2]={{10, 8},
                   {5 ,14},
                   {10,23},
                   {25, 7},
                   {8 ,30},
                   {14,16},
                   {6 ,13},
                   {5 ,10},
                   {25, 6},
                   {4 ,15}};

int main(){
    int counter;

    //Sort first column in ascending order
    do {
        counter  = 0;

        for (int i = 0; i < 9; i++) {
            if(Reorder(&matrix[i][0],&matrix[i+1][0])){
                counter++;
            }
        }
    } while (counter != 0);

    //Sort second column in descending order
    do {
        counter  = 0;
        for (int i = 9; i > 0 ; i--) {
            if(Reorder(&matrix[i][1],&matrix[i-1][1])){
                counter++;
            }
        }
    } while (counter != 0);

    //Print on the screen
    printf("SORTED MATRIX \nFirst column is in ascending order.\nSecond column is in descending order.\n");

    for (int i = 0; i < 10; ++i) {
        printf("%d\t%d\n",matrix[i][0],matrix[i][1]);
    }

    printf("\nTRANSPOSE OF SORTED MATRIX :\n");

    for (int i = 0; i < 10; ++i) {
        printf("%d\t",matrix[i][0]);
    }

    printf("\n");

    for (int i = 0; i < 10; ++i) {
        printf("%d\t",matrix[i][1]);
    }

    return 0;
}

// Here is a function used for increasing reusability.
// Takes 2 int pointers as parameters.
// If they needs reorder returns true, otherwise false
int Reorder(int *min, int *max){

    if(*min>*max){
        int cache = *min;
        *min = *max;
        *max = cache;
        //printf("min : %d, max: %d, cache: %d", *min, *max, cache);
        return 1;
    }
    return 0;
}
