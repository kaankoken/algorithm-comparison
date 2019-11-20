#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
    Available on github after deadline
    <a href ="https://github.com/kaankoken/algorithm-comparison">Github</a>
    Kaan Taha Köken - 2152064
*/

//prototypes of the funcitons;
void printList(int *, int);
int findMin(int *, int);
int findMax(int *, int);
void insertionSort(int *, int);

int main(int argc, char **argv) {
    struct timeval tval_before, tval_after;
    int *listOfNumber, n, i;
    int min, max, range;

    //reads how many inputs will be in the program
    scanf("%d", &n);
    listOfNumber =  (int *)malloc(sizeof(int)* n);    
    //it will fill the list with inputs
    for (i = 0; i < n; i++)
        scanf("%d", (listOfNumber + i));
    //printList(listOfNumber, n);

    min = findMin(listOfNumber, n);
    max = findMax(listOfNumber, n);
    //Determine the range using minumum and maximum values on the list
    range = max - min;

    int **bucket;
    bucket = (int **)malloc(sizeof(int*) * 10);
    
    int *size;
    size = (int *)malloc(sizeof(int) * 10);
    
    for (i = 0; i < 10; i++)
        *(bucket + i) = (int *)malloc(sizeof(int) * 1);
    for (i = 0; i < 10; i++)
        size[i] = 0;
    gettimeofday(&tval_before, NULL);    
    for (i = 0; i < n; i++)  {
        if (min <= listOfNumber[i] && listOfNumber[i] < ((min + range) / 10)) {
            size[0]++;
            bucket[0] = (int *)realloc(bucket[0], sizeof(int) * size[0]);
            bucket[0][size[0] - 1] = listOfNumber[i];
        }
        else if (((min + range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 2 * range) / 10)) {
            size[1]++;
            bucket[1] = (int *)realloc(bucket[1], sizeof(int) * size[1]);
            bucket[1][size[1] - 1] = listOfNumber[i];
        }
        else if (((min + 2 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 3 * range) / 10)) {
            size[2]++;
            bucket[2] = (int *)realloc(bucket[2], sizeof(int) * size[2]);
            bucket[2][size[2] - 1] = listOfNumber[i];
        }
        else if (((min + 3 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 4 * range) / 10)) {
            size[3]++;
            bucket[3] = (int *)realloc(bucket[3], sizeof(int) * size[3]);
            bucket[3][size[3] - 1] = listOfNumber[i];
        }
        else if (((min + 4 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 5 * range) / 10)) {
            size[4]++;
            bucket[4] = (int *)realloc(bucket[4], sizeof(int) * size[4]);
            bucket[4][size[4] - 1] = listOfNumber[i];
        }
        else if (((min + 5 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 6 * range) / 10)) {
            size[5]++;
            bucket[5] = (int *)realloc(bucket[5], sizeof(int) * size[5]);
            bucket[5][size[5] - 1] = listOfNumber[i];
        }
        else if (((min + 6 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 7 * range) / 10)) {
            size[6]++;
            bucket[6] = (int *)realloc(bucket[6], sizeof(int) * size[6]);
            bucket[6][size[6] - 1] = listOfNumber[i];
        }
        else if (((min + 7 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 8 * range) / 10)) {
            size[7]++;
            bucket[7] = (int *)realloc(bucket[7], sizeof(int) * size[7]);
            bucket[7][size[7] - 1] = listOfNumber[i];
        }
        else if (((min + 8 * range) / 10) <= listOfNumber[i] && listOfNumber[i] < ((min + 9 * range) / 10)) {
            size[8]++;
            bucket[8] = (int *)realloc(bucket[8], sizeof(int) * size[8]);
            bucket[8][size[8] - 1] = listOfNumber[i];
        }
        else if (((min + 9 * range) / 10) <= listOfNumber[i] && listOfNumber[i] <= max) {
            size[9]++;
            bucket[9] = (int *)realloc(bucket[9], sizeof(int) * size[9]);
            bucket[9][size[9] - 1] = listOfNumber[i];
        }
    }

    for (i = 0; i < 10; i++) {
        insertionSort(bucket[i], size[i]);
        printList(bucket[i], size[i]);
    }
    gettimeofday(&tval_after, NULL);
    printf("Started at: %ld.%06ld\n", (long int)tval_before.tv_sec, (long int)tval_before.tv_usec);
	printf("Ended at: %ld.%06ld\n", (long int)tval_after.tv_sec, (long int)tval_after.tv_usec);
    for (i = 0; i < 10; i++) {
        free(bucket[i]);
    }

    gettimeofday(&tval_before, NULL);    
    insertionSort(listOfNumber, 100000);
    gettimeofday(&tval_after, NULL);
    printf("Started at: %ld.%06ld\n", (long int)tval_before.tv_sec, (long int)tval_before.tv_usec);
	printf("Ended at: %ld.%06ld\n", (long int)tval_after.tv_sec, (long int)tval_after.tv_usec);
    
    free(bucket);
    free(size);
    free(listOfNumber);
    return 0;
}

//displays the items in that list
void printList(int *listOfNumber, int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d\n", listOfNumber[i]);
}
//Function return minimum number in the array
int findMin(int *listOfNumber, int n) {
    int i, min = listOfNumber[0];
    for (i = 1; i < n; i++) {
        if (min > *(listOfNumber + i))
            min = *(listOfNumber + i);

    }
    return min;
}
//Function return maximum number in the array
int findMax(int *listOfNumber, int n) {
    int i, max = listOfNumber[0];
    for (i = 1; i < n; i++) {
        if (max < *(listOfNumber + i))
            max = *(listOfNumber + i);
    }
    return max;
}
//this is the classic insertion sort implementation
void insertionSort(int *list, int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = list[i];
        j = i - 1;

        while (j >= 0 && list[j] > key) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = key;
    }
}