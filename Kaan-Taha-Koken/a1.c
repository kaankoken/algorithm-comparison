#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Available on github after deadline
    <a href ="https://github.com/kaankoken/algorithm-comparison">Github</a>
    Kaan Taha Köken - 2152064
*/
//prototypes of the funcitons
int findMin(int *, int);
int findMax(int *, int);

int main(int argc, char **argv) {
    int *listOfNumber, n, i;
    int min, max, range;
    scanf("%d", &n);
    listOfNumber =  (int *)malloc(sizeof(int)* n - 1);    

    for (i = 1; i <= n; i++)
        scanf("%d", (listOfNumber + i));
    min = findMin(listOfNumber, n);
    max = findMax(listOfNumber, n);
    range = max - min;
    
    return 0;
}

//Function return minimum number in the array
int findMin(int *listOfNumber, int n) {
    int i, min = listOfNumber[1];
    for (i = 1; i <= n; i++) {
        if (min > *(listOfNumber + i))
            min = *(listOfNumber + i);

    }
    return min;
}

int findMax(int *listOfNumber, int n) {
    int i, max = listOfNumber[1];
    for (i = 1; i <= n; i++) {
        if (max < *(listOfNumber + i))
            max = *(listOfNumber + i);
    }
}