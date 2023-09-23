#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int arr[500];
    int n, i;

    inputFile = fopen("inAsce.dat", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }
    fclose(inputFile);

    clock_t start_time = clock();
    quick_sort(arr, 0, n - 1);
    clock_t end_time = clock();
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;


    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Comparisons: %d\n", comparisons);
    printf("Execution Time: %lf seconds\n", execution_time);

    outputFile = fopen("outQuickAsce.dat", "w");
    if (outputFile != NULL) {
        for (i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
        }
        fclose(outputFile);
    } else {
        printf("Failed to open output file.\n");
    }

    if (comparisons == n - 1) {
        printf("Best-case partitioning.\n");
    } else if (comparisons == (n * (n - 1)) / 2) {
        printf("Worst-case partitioning.\n");
    } else {
        printf("Intermediate partitioning.\n");
    }

    return 0;
}
