#include <stdio.h>
#include <limits.h>

#define MAX_MATRICES 10

void matrix_chain_order(int p[], int n, int m[MAX_MATRICES][MAX_MATRICES], int s[MAX_MATRICES][MAX_MATRICES]) {
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parenthesis(int s[MAX_MATRICES][MAX_MATRICES], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parenthesis(s, i, s[i][j]);
        print_optimal_parenthesis(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int dimensions[MAX_MATRICES + 1];
    for (int i = 0; i < n + 1; i++) {
    printf("Enter the row and column size of A%d: ", i + 1);
    scanf("%d %d", &dimensions[i], &dimensions[i + 1]);
}


    int m[MAX_MATRICES][MAX_MATRICES];
    int s[MAX_MATRICES][MAX_MATRICES];

    matrix_chain_order(dimensions, n + 1, m, s);

    printf("M Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("S Table:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("Optimal parenthesization: ");
    print_optimal_parenthesis(s, 1, n);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[1][n]);

    return 0;
}
