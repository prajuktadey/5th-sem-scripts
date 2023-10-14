#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    // Build the L[m+1][n+1] matrix in a bottom-up fashion
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // The length of LCS is stored in L[m][n]
    int length = L[m][n];

    // The LCS string can be reconstructed from the L[m+1][n+1] matrix
    char lcs[length + 1];
    lcs[length] = '\0';

    // Start from the right-most bottom corner and move up
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[length - 1] = X[i - 1];
            i--;
            j--;
            length--;
        } else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS: %s\n", lcs);
    printf("LCS Length: %d\n", L[m][n]);
}

int main() {
    char X[100], Y[100];

    printf("Enter the first string into an array: ");
    scanf("%s", X);
    printf("Enter the second string into an array: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
