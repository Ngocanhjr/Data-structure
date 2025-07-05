#include <stdio.h>

int main() {
#if 0
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {  // đưa số lớn ra sau
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
    }
#endif

#if 1
    int n, m;
    scanf("%d%d", &n, &m);

    int cnt = 0;
    int A[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] > 0) cnt++;
        }
    }

    printf("%d", cnt);
#endif
}