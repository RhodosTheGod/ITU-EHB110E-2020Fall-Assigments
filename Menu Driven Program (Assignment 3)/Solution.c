#include <stdio.h>
#include <string.h>
#include "persons.h"

void printArray();
void handleInput();
void getPageCapacity();
int pageCapacity;
int pageNumber = 1;
int lastPage;
int sizeOfArray;

int main(){
    getPageCapacity();

    sizeOfArray = sizeof(Liste) / sizeof(Liste[0]);

    //find last page number
    lastPage = (sizeOfArray % pageCapacity) == 0 ? sizeOfArray / pageCapacity : (sizeOfArray / pageCapacity) + 1;

    printArray();
    handleInput();

    return 0;
}
void getPageCapacity() {
    printf("ENTER NUMBER OF PERSONS PER ONE PAGE (BETWEEN 1-30) : ");
    scanf("%d", &pageCapacity);

    if (pageCapacity > 30 || pageCapacity < 0) {
        printf("ERROR! PAGE CAPACITY IS OUT OF THE BOUNDS\n");
        getPageCapacity();
    }
}
void handleInput() {
    printf("ENTER PAGE NAVIGATION COMMAND (F:first, L:last, N:next, P:previous, X:exit) : ");
    char command;
    scanf(" %c",&command);

    switch (command) {
        case 'F':
            pageNumber = 1;
            printArray();
            handleInput();
            break;
        case 'L':
            pageNumber = lastPage;
            printArray();
            handleInput();
            break;
        case 'N':
            //error handling
            if(pageNumber==lastPage){
                printf("WRONG INPUT! THIS WAS THE LAST PAGE ALREADY.\n");
            }
            else{
                pageNumber++;
                printArray();
            }
            handleInput();
            break;
        case 'P':
           //error handling
            if(pageNumber==1){
                printf("WRONG INPUT! THIS WAS THE FIRST PAGE ALREADY.\n");
            }
            else{
                pageNumber--;
                printArray();
            }
            handleInput();
            break;
        case 'X':
            break;
        default:
            printf("YOU ENTERED AN UNIDENTIFIED INPUT. ");
            handleInput();
            break;
    }
}

void printArray() {
    printf("CURRENT PAGE NUM : %d\nNo FName\tLName\n", pageNumber);
    printf("== =====\t=====\n");

    int upper = lastPage == pageNumber ? sizeOfArray : pageNumber * pageCapacity;

    for (int i = (pageNumber - 1) * pageCapacity; i < upper; ++i) {
        //4 character names isn't aligning well with 1 tab
        if(strlen(Liste[i].FName) <= 4)
            printf("%02d %s\t\t%s\n", (i + 1), Liste[i].FName, Liste[i].LName);
        else
            printf("%02d %s\t%s\n", (i + 1), Liste[i].FName, Liste[i].LName);
    }
}