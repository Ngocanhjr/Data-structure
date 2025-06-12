 int n;
    scanf("%d",&n);
    int col = 2*n - 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int k = n - i - 1; k < n; k++){
            printf("*");
        }

        // for(int j = n - i; j < col + i; j++){
        //     printf("*");
        // }
        for(int j = 0; j < n + i - 4; j++){
            printf("*");
        }
        printf("\n");
    }