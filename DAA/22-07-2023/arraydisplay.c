#include <stdio.h>
 
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n); 

    int a[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter a number: ");
        scanf("%d", &a[i]);
    }

    for(int j=0; j<n; j++)
    {
        printf("%d", a[j]);
    }
    return 0;
}