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

    int max = a[0];
    int secondMax = a[0]; 

    for (int k = 1; k < n; k++) {
        if (a[k] > max) {
            secondMax = max; 
            max = a[k]; 
        } else if (a[k] > secondMax && a[k] < max) {
            secondMax = a[k]; 
        }
    }

    printf("The maximum element: %d\n", max);
    printf("The second greatest element: %d\n", secondMax);

    return 0;
}
