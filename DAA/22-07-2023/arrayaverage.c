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

    int sum = 0;
    for (int k = 0; k < n; k++) {
        sum = sum + a[k];
    }

    float average = (float)sum / n;

    printf("The average is: %.2f\n", average);

    return 0;
}
