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

    for(int k=0; k < n; k++)
    {
        if(a[k]%2==0)
        {
            printf("Even: %d", a[k]);
            printf("\n");
        }
        else{
            printf("Odd: %d", a[k]);
            printf("\n");
        }
    }
    return 0;
}
