#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
         k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    int arr[500];
    int n, i;

    inputFile = fopen("inAsce.dat", "r");  // Change filename as needed
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
    merge_sort(arr, 0, n - 1);
    clock_t end_time = clock();
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Comparisons: %d\n", comparisons);
    printf("Execution Time: %lf seconds\n", execution_time);

    outputFile = fopen("outMergeAsce.dat", "w");  // Change filename as needed
    if (outputFile != NULL) {
        for (i = 0; i < n; i++) {
            fprintf(outputFile, "%d ", arr[i]);
        }
        fclose(outputFile);
    } else {
        printf("Failed to open output file.\n");
    }

    return 0;
}
