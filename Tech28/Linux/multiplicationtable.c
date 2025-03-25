#include <stdio.h>

int main(int argc, char *argv[])
{
    int arg = atoi(argv[1]); // Convert argument to integer
    // check input
   

    printf("Multiplication table: \n");

    for (int i = 1; i <= 10; i++)
    {
        printf("%dx%d = %d\n", arg, i, arg * i);
    }

    return 0;
}