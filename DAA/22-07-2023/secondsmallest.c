#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n); 

    int a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &a[i]);
    }

    for (int j = 0; j < n; j++) {
        printf("%d\n", a[j]);
    }

    int min = a[0];
    int secondMin = a[1];

    if (min > secondMin) {
        int temp = min;
        min = secondMin;
        secondMin = temp;
    }

    for (int k = 2; k < n; k++) {
        if (a[k] < min) {
            secondMin = min;
            min = a[k];
        } else if (a[k] < secondMin && a[k] != min) {
            secondMin = a[k];
        }
    }

    if (secondMin != min) {
        printf("The second smallest element: %d\n", secondMin);
    } else {
        printf("There is no distinct second smallest element.\n");
    }

    return 0;
}
