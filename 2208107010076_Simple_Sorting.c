#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBERS 1000000 
#define INCREASE_AMOUNT 100000

void generateRandomNumbers(int array[], int size) {
    srand(time(NULL)); // Inisialisasi seed untuk fungsi rand()
    for (int i = 0; i < size; i++) {
        array[i] = rand();
    }
}

// perform the bubble sort
void bubbleSort(int array[], int size){
    // loop to access each array element
    for (int step = 0; step < size - 1; ++step){
        // loop to compare array elements
        for (int i = 0; i < size - step - 1; ++i){
            // compare two adjacent elements
            // change > to < to sort in descending order
            if (array[i] > array[i + 1]){
                // swapping occurs if elements
                // are not in the intended order
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size){
    for (int step = 0; step < size - 1; step++){
        int min_idx = step;
        for (int i = step + 1; i < size; i++){
            // To sort in descending order, change > to < in this line.
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
                min_idx = i;
        }
        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step] = temp;
    }
}

void insertionSort(int array[], int size){
    for (int step = 1; step < size; step++){
        int key = array[step];
        int j = step - 1;

        // Compare key with each element on the left of it until an element smaller than
        // it is found.
        // For descending order, change key<array[j] to key>array[j].
        while (key < array[j] && j >= 0){
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void saveToFile(int array[], int size, char *filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", array[i]);
    }

    fclose(file);
}

int main(){
    int *numbers = malloc(MAX_NUMBERS * sizeof(int));
    generateRandomNumbers(numbers, MAX_NUMBERS);
    saveToFile(numbers, MAX_NUMBERS, "unsorted.txt");

    clock_t start, end;
    double cpu_time_used;

    for (int n = INCREASE_AMOUNT; n <= MAX_NUMBERS; n += INCREASE_AMOUNT) {
        int *arr = malloc(n * sizeof(int));
        // Bubble sort
        memcpy(arr, numbers, n * sizeof(int));
        start = clock();
        bubbleSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("\n=====================================================================\n");
        printf("Bubble Sort     |      %d      |     %f ms\n", n, cpu_time_used*1000);

        // Selection sort
        memcpy(arr, numbers, n * sizeof(int));
        start = clock();
        selectionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Selection Sort  |      %d      |     %f ms\n", n, cpu_time_used*1000);

        // Insertion sort
        memcpy(arr, numbers, n * sizeof(int));
        start = clock();
        insertionSort(arr, n);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Insertion Sort  |      %d      |     %f ms\n", n, cpu_time_used*1000);

        if (n == MAX_NUMBERS)
        {
            memcpy(numbers, arr, MAX_NUMBERS * sizeof(int));
        }
    }

    saveToFile(numbers, MAX_NUMBERS, "sorted.txt");

    return 0;
}