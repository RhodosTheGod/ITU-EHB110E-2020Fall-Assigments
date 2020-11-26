#include <stdio.h>

void Reorder(int* min, int* max);

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
    //Maybe we will want to change matrix later, who knows?
    const int LENGTH_OF_ROW = sizeof(matrix)/sizeof(matrix[0]);

    //Sort first column in ascending order
    for (int i = LENGTH_OF_ROW -1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            Reorder(&matrix[j][0],&matrix[j+1][0]);
        }
    }

    //Sort second column in descending order
    for (int i = 0; i < LENGTH_OF_ROW; i++)
    {
        for (int j = LENGTH_OF_ROW - 1; j > i; j--)
        {
            Reorder(&matrix[j][1],&matrix[j-1][1]);
        }
    }

    //Print on the screen
    printf("SORTED MATRIX \nFirst column is in ascending order.\nSecond column is in descending order.\n");

    for (int i = 0; i < LENGTH_OF_ROW; ++i) {
        printf("%d\t%d\n",matrix[i][0],matrix[i][1]);
    }

    printf("\nTRANSPOSE OF SORTED MATRIX :\n");

    for (int i = 0; i < LENGTH_OF_ROW; ++i) {
        printf("%d\t",matrix[i][0]);
    }

    printf("\n");

    for (int i = 0; i < LENGTH_OF_ROW; ++i) {
        printf("%d\t",matrix[i][1]);
    }

    return 0;
}

// Here is a function used for increasing reusability.
// Takes 2 int pointers as parameters.
void Reorder(int *min, int *max){

    if(*min>*max){
        int cache = *min;
        *min = *max;
        *max = cache;
        //printf("min : %d, max: %d, cache: %d", *min, *max, cache);
     }
}
