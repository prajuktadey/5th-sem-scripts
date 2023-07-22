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
    for (int k = 1; k < n; k++) {
        if (a[k] < min) {
            min = a[k];
        }
    }

    printf("The minimum element: %d\n", min);

    return 0;
}
