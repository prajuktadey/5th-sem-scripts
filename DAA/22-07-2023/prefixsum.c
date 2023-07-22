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

    int prefixsum[n];
    prefixsum[0] = a[0];

    for (int m = 1; m < n; m++) {
        prefixsum[m] = prefixsum[m - 1] + a[m];
    }

    printf("The prefix sum is: ");
    for (int k = 0; k < n; k++) {
        printf("%d ", prefixsum[k]);
    }

    return 0;
}
