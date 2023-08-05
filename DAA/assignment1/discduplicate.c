#include <stdio.h>
#include <stdlib.h>

int countDuplicates(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break; 
            }
        }
    }

    return count;
}

int Repeating(int arr[], int n) {
    int mostRepeatingElement = arr[0];
    int maxFrequency = 1;

    for (int i = 0; i < n; i++) {
        int frequency = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                frequency++;
            }
        }
        if (frequency > maxFrequency) {
            maxFrequency = frequency;
            Repeating = arr[i];
        }
    }

    return mostRepeatingElement;
}

int main() {
    FILE *file;
    int n;

    // Open the file in read mode
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.");
        return 1;
    }

    // Read 'n' from the file
    fscanf(file, "%d", &n);

    // Allocate memory for the array dynamically
    int *arr = (int *)malloc(n * sizeof(int));

    // Read 'n' integers from the file and store them into the array
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    // Close the file
    fclose(file);

    // Perform the required operations
    int totalDuplicates = countDuplicates(arr, n);
    int mostRepeatingElement = findMostRepeating(arr, n);

    // Display the results
    printf("Total number of duplicate elements: %d\n", totalDuplicates);
    printf("Most repeating element: %d\n", mostRepeatingElement);

    // Free the allocated memory
    free(arr);

    return 0;
}
