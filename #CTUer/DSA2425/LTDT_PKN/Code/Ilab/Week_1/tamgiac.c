#include <stdio.h>

int main() {
#if 0
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            printf("*");
        }
        printf("\n");
    }
#endif

#if 0
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int k = n - i - 1; k < n; k++){
            printf("*");
        }
        printf("\n");
    }
#endif

#if 1
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int k = n - i - 1; k < n; k++){
            printf("*");
        }

        for(int h = n + i ; h < n + 2*i; h++){
            printf("*");
        }
        // for(int j = 0; j < n + i - 4; j++){
        //     printf("*");
        // }
        printf("\n");
    }
#endif
}
