#include "add.h"
#include "BubbleSort.h"
#include "printResult.h"
#include <time.h>

#define bool char
#define true 1
#define false 0
#define LENGTH 10

int main(){
    int a[LENGTH], i;
    int b[LENGTH];
    int randValue = 0;
    srand(time(NULL));
    for(i = 0; i < LENGTH; i++) {
        randValue = 1 + (int)rand() % LENGTH;
        a[i] = randValue;
        b[i] = a[i];
    }
    printResult(a, LENGTH, "\nrandom array: ");
    bool flag = true;
    while(flag) {
        printf("\n1.Bubble Sort\n2.sum\n3.print result\n4.exit");
        printf("\nchoose a number:");
        int number = 0;
        scanf("%d", &number);
        int sum = 0;
        switch(number)
        {
            case 1:
                BubbleSort(a, LENGTH);
                break;
            case 2:
                sum = add(a, LENGTH);
                printf("\nresult of sum: %d\n", sum);
                break;
            case 3:
                printResult(b, LENGTH, "\noriginal array:\t");
                printResult(a, LENGTH, "\nsorted array:\t");
            case 4:
                flag = false;
                break;
            default:
                printf("\nplease choose a correct number and continue!");
                break;
        }
        printf("\nDone!\n\n");
    }
    return 0;
}