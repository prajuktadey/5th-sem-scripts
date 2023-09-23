#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct person
struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function to swap two persons
void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a min-heap
void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Function to display the weight of the youngest person
void displayYoungestWeight(struct person arr[], int n) {
    if (n == 0) {
        printf("Heap is empty.\n");
        return;
    }
    printf("Weight of youngest student: %.2f kg\n", arr[0].weight / 2.20462); // Convert pounds to kilograms
}

// Function to insert a new person into the min-heap
void insertIntoMinHeap(struct person arr[], int *n, struct person newPerson) {
    (*n)++;
    int i = *n - 1;
    arr[i] = newPerson;

    while (i > 0 && arr[(i - 1) / 2].age > arr[i].age) {
        swap(&arr[i], &arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to delete the oldest person from the min-heap
void deleteOldestPerson(struct person arr[], int *n) {
    if (*n <= 0) {
        printf("Heap is empty. Cannot delete.\n");
        return;
    }
    if (*n == 1) {
        (*n)--;
        return;
    }

    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
}

int main() {
    int option, n = 0;
    struct person *people = NULL;
    FILE *file = NULL;

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (file != NULL) {
                    fclose(file);
                    free(people);
                }

                file = fopen("data.txt", "r");
                if (file == NULL) {
                    printf("Error: Unable to open the file.\n");
                    break;
                }

                fscanf(file, "%d", &n);
                people = (struct person *)malloc(n * sizeof(struct person));

                for (int i = 0; i < n; i++) {
                    people[i].id = i;
                    fscanf(file, "%s %d %d %d", people[i].name, &people[i].age, &people[i].height, &people[i].weight);
                }
                fclose(file);
                printf("Data loaded successfully.\n");
                break;

            case 2:
                if (n > 0) {
                    buildMinHeap(people, n);
                    printf("Min-heap based on age created.\n");
                } else {
                    printf("No data to create a heap.\n");
                }
                break;

            case 3:
                if (n > 0) {
                    for (int i = 0; i < n; i++)
                        people[i].weight *= -1;
                    buildMinHeap(people, n);
                    for (int i = 0; i < n; i++)
                        people[i].weight *= -1;
                    printf("Max-heap based on weight created.\n");
                } else {
                    printf("No data to create a heap.\n");
                }
                break;

            case 4:
                displayYoungestWeight(people, n);
                break;

            case 5:
                if (n >= 100) {
                    printf("Heap is full. Cannot insert more persons.\n");
                } else {
                    struct person newPerson;
                    printf("Enter the details of the new person:\n");
                    newPerson.id = n;
                    scanf("%s %d %d %d", newPerson.name, &newPerson.age, &newPerson.height, &newPerson.weight);
                    insertIntoMinHeap(people, &n, newPerson);
                    printf("New person inserted into the Min-heap.\n");
                }
                break;

            case 6:
                deleteOldestPerson(people, &n);
                printf("Oldest person deleted from the Min-heap.\n");
                break;

            case 7:
               
                if (file != NULL)
                    fclose(file);
                free(people);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid Option, try again later.")
        }
    } while (1);

    return 0;
}